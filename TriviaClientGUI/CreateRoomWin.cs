using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TriviaClientGUI
{
    public partial class CreateRoomWin : Form
    {
        public CreateRoomWin()
        {
            InitializeComponent();
        }

        private void BackToMenuBTN_Click(object sender, EventArgs e)
        {
            MenuWin nextForm = new MenuWin(); // go back to menu
            Hide();
            nextForm.ShowDialog();
            Close();
            ErrorProvider.SetError(BackToMenuBTN, "ERRE");
        }

        private void CreateRoomBTN_Click(object sender, EventArgs e)
        {
            ErrorProvider.Clear();
            if(RoomNameTB.Text.Trim().Length < 4) // validate Room name 
            {
                ErrorProvider.SetError(RoomNameTB, "Room name needs to be longer the 3 characters");
                return;
            }
            string payload = JsonConvert.SerializeObject(new { RoomName = RoomNameTB.Text.Trim(), MaxUsers = MaxUsersNUD.Value, QuestionCount = QuestionCountNUD.Value, AnswerTimeout = AnswerTimeoutNUD.Value});
            string createRoomResponse = Client.SendPayload('C', payload); // send create room request
            if (createRoomResponse == "server has died")
            {
                LoginWin nextForm = new LoginWin(); // logout
                Hide();
                nextForm.ShowDialog();
                Close();
            }
            else if (createRoomResponse != "server is dead")
            {
                StatusResponse deserializeCreateRoomResponse = JsonConvert.DeserializeObject<StatusResponse>(createRoomResponse);
                if (deserializeCreateRoomResponse.Status == 0) // if user already in a room
                {
                    ErrorProvider.SetError(CreateRoomBTN, "User already in a room, don't try to hack :)");
                }
                else
                { // creat new wait for game window
                    WaitForGameWin nextForm = new WaitForGameWin(true, RoomNameTB.Text.Trim());
                    Hide();
                    nextForm.ShowDialog();
                    Close();
                }
            }
        }

        private void RoomNameTB_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (Encoding.UTF8.GetByteCount(new char[] { e.KeyChar }) > 1)
            {
                e.Handled = true;
            }
        }

        private void CreateRoomWin_Load(object sender, EventArgs e)
        {
            MaximizeBox = false;
        }
    }
}
