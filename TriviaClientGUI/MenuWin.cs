using Newtonsoft.Json;
using System;
using System.Drawing;
using System.Windows.Forms;

namespace TriviaClientGUI
{
    public partial class MenuWin : Form
    {
        public MenuWin()
        {
            InitializeComponent();
        }

        private void CreateRoomBTN_Click(object sender, EventArgs e)
        {
            CreateRoomWin nextForm = new CreateRoomWin(); // create new create room window
            Hide();
            nextForm.ShowDialog();
            Close();
        }

        private void LogoutBTN_Click(object sender, EventArgs e)
        {
            ErrorProvider.Clear();
            string loginResponse = Client.SendPayload('O', ""); // send logout request
            if(loginResponse == "server has died")
            {
                LoginWin nextForm = new LoginWin(); // logout
                Hide();
                nextForm.ShowDialog();
                Close();
            }
            else if (loginResponse != "server is dead")
            {     
                StatusResponse deserializeLoginResponse = JsonConvert.DeserializeObject<StatusResponse>(loginResponse);
                if (deserializeLoginResponse.Status == 0)
                {
                    ErrorProvider.SetError(LogoutBTN, "Error, don't try to hack :)"); // error with logout, can't happend normaly - just from a script
                }
                else
                {
                    LoginWin nextForm = new LoginWin(); // logout
                    Hide();
                    nextForm.ShowDialog();
                    Close();
                }
            }
        }

        private void JoinRoomBTN_Click(object sender, EventArgs e)
        {
            RoomsWin nextForm = new RoomsWin(); // create new rooms window
            Hide();
            nextForm.ShowDialog();
            Close();
        }

        private void StatisticsBTN_Click(object sender, EventArgs e)
        {
            StatisticsWin nextForm = new StatisticsWin(); // create new statistics window
            Hide();
            nextForm.ShowDialog();
            Close();
        }

        private void MenuWin_Load(object sender, EventArgs e)
        {
            MaximizeBox = false;
            HelloLBL.Text = "Hello " + Properties.Settings.Default.username; // loude the username from the settings
        }
    }
}
