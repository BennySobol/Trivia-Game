using Newtonsoft.Json;
using System;

using System.Windows.Forms;

namespace TriviaClientGUI
{
    public partial class WaitForGameWin : Form
    {
        private readonly bool isCreator;
        private readonly string roomName;
        public WaitForGameWin(bool isCreator, string roomName)
        {
            this.roomName = roomName;
            this.isCreator = isCreator;
            InitializeComponent();
        }

        private void WaitForGameWin_Load(object sender, EventArgs e)
        {
            if(!isCreator) // display the correct buttons and text
            {
                StartGameBTN.Visible = false;
                CloseGameBTN.Text = "Leave Game";
            }
            RNLBL.Text = "Room Name: " + roomName;
            RefreshForm();
        }

        private void RefreshForm()
        {
            string getRoomStateResponse = Tools.SendPayload('?', ""); // send get room state request
            if (getRoomStateResponse == "server has died")
            {
                LoginWin nextForm = new LoginWin(); // logout
                Hide();
                nextForm.ShowDialog();
                Close();
            }
            else if (getRoomStateResponse != "server is dead")
            {
                GetRoomState deserializeGetGetRoomStatusResponse = JsonConvert.DeserializeObject<GetRoomState>(getRoomStateResponse);
                if (deserializeGetGetRoomStatusResponse.Status == 1)
                {
                    if (deserializeGetGetRoomStatusResponse.HasGameBegun) // if the game started
                    {
                        timer.Stop();
                        TriviaWin nextForm = new TriviaWin(); // open the trivia window
                        Hide();
                        nextForm.ShowDialog();
                        Close();
                    }
                    NOQLBL.Text = "Number Of Questions: " + deserializeGetGetRoomStatusResponse.QuestionCount.ToString();
                    TPQLBL.Text = "Time Per Question: " + deserializeGetGetRoomStatusResponse.AnswerTimeout.ToString();

                    UsersLV.Items.Clear();
                    foreach (Player player in deserializeGetGetRoomStatusResponse.PlayersInRoom) // display players
                    {
                        UsersLV.Items.Add(new ListViewItem(player.PlayerName));
                    }
                }
                else
                {
                    timer.Stop();
                    MessageBox.Show("The room have been closed", "Error Detected");
                    MenuWin nextForm = new MenuWin(); // back to the menu
                    Hide();
                    nextForm.ShowDialog();
                    Close();
                }
            }
        }
        
        private void StartGameBTN_Click(object sender, EventArgs e)
        {
            timer.Stop();
            ErrorProvider.Clear();
            string startGameResponse = Tools.SendPayload('A', ""); // send start game request
            if (startGameResponse == "server has died")
            {
                LoginWin nextForm = new LoginWin(); // logout
                Hide();
                nextForm.ShowDialog();
                Close();
            }
            if (startGameResponse != "server is dead")
            {
                StatusResponse deserializeStartGameResponse = JsonConvert.DeserializeObject<StatusResponse>(startGameResponse);
                if (deserializeStartGameResponse.Status == 0)
                {
                    ErrorProvider.SetError(StartGameBTN, "Error, don't try to hack :)");
                }
            }
            else
            {
                TriviaWin nextForm = new TriviaWin(); // open the trivia window
                Hide();
                nextForm.ShowDialog();
                Close();
            }
        }
        

        private void CloseGameBTN_Click(object sender, EventArgs e)
        {
            timer.Stop();
            if(isCreator) // close the room
            {
                ErrorProvider.Clear();
                string loginResponse = Tools.SendPayload('~', ""); // send logout request
                if (loginResponse == "server has died")
                {
                    LoginWin nextForm = new LoginWin(); // logout
                    Hide();
                    nextForm.ShowDialog();
                    Close();
                }
                if (loginResponse != "server is dead")
                {
                    StatusResponse deserializeLoginResponse = JsonConvert.DeserializeObject<StatusResponse>(loginResponse);
                    if (deserializeLoginResponse.Status == 0)
                    {
                        ErrorProvider.SetError(StartGameBTN, "Error, don't try to hack :)"); // error with logout, can't happend normaly - just from a script
                    }
                    else
                    {
                        MenuWin nextForm = new MenuWin(); // back to the menu
                        Hide();
                        nextForm.ShowDialog();
                        Close();
                    }
                }
            }
            else // leave the room
            {
                ErrorProvider.Clear();
                string leaveRoomResponse = Tools.SendPayload('V', ""); // send leave room request
                if (leaveRoomResponse == "server has died")
                {
                    LoginWin nextForm = new LoginWin(); // logout
                    Hide();
                    nextForm.ShowDialog();
                    Close();
                }
                if (leaveRoomResponse != "server is dead")
                {
                    StatusResponse deserializeLeaveRoomResponseResponse = JsonConvert.DeserializeObject<StatusResponse>(leaveRoomResponse);
                    if (deserializeLeaveRoomResponseResponse.Status == 0)
                    {
                        ErrorProvider.SetError(CloseGameBTN, "Error, don't try to hack :)"); 
                    }
                    else
                    {
                        MenuWin nextForm = new MenuWin(); // back to the menu
                        Hide();
                        nextForm.ShowDialog();
                        Close();
                    }
                }
            }
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            RefreshForm(); // refresh form every second
        }
    }
}
