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
            MaximizeBox = false;
            if (!isCreator) // display the correct buttons and text
            {
                StartGameBTN.Visible = false;
                CloseGameBTN.Text = "Leave Game";
            }
            RNLBL.Text = "Room Name: " + roomName;
            RefreshForm();
        }

        private void RefreshForm()
        {
            try
            {
                string getRoomStateResponse = Client.SendPayload('?', ""); // send get room state request
                if (getRoomStateResponse == "server has died")
                {
                    timer.Stop();
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
                            TriviaWin nextForm = new TriviaWin(Int32.Parse(NOQLBL.Text.Substring(21)), Int32.Parse(TPQLBL.Text.Substring(19))); // open the trivia window
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
                        // leave room
                        LeaveRoom();
                    }
                }
            }
            catch { } // will catch error responce from the server
        }
        
        private void StartGameBTN_Click(object sender, EventArgs e)
        {
            timer.Stop();
            ErrorProvider.Clear();
            string startGameResponse = Client.SendPayload('A', ""); // send start game request
            if (startGameResponse == "server has died")
            {
                timer.Stop();
                LoginWin nextForm = new LoginWin(); // logout
                Hide();
                nextForm.ShowDialog();
                Close();
            }
            else if (startGameResponse != "server is dead")
            {
                StatusResponse deserializeStartGameResponse = JsonConvert.DeserializeObject<StatusResponse>(startGameResponse);
                if (deserializeStartGameResponse.Status == 0)
                {
                    ErrorProvider.SetError(StartGameBTN, "Error, don't try to hack :)");
                }
                else
                {
                    TriviaWin nextForm = new TriviaWin(Int32.Parse(NOQLBL.Text.Substring(21)), Int32.Parse(TPQLBL.Text.Substring(19))); // open the trivia window
                    Hide();
                    nextForm.ShowDialog();
                    Close();
                }
            }
        }
        
        private void CloseGameBTN_Click(object sender, EventArgs e)
        {
            timer.Stop();
            if (isCreator) // close the room
            {
                ErrorProvider.Clear();
                string loginResponse = Client.SendPayload('~', ""); // send logout request
                if (loginResponse == "server has died")
                {
                    timer.Stop();
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
                LeaveRoom();
            }
        }

        // this function send a leave request and leave the room
        private void LeaveRoom()
        {
            ErrorProvider.Clear();
            string leaveRoomResponse = Client.SendPayload('V', ""); // send leave room request
            if (leaveRoomResponse == "server has died")
            {
                timer.Stop();
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
        private void Timer_Tick(object sender, EventArgs e)
        {
            RefreshForm(); // refresh form every second
        }

        private void UsersLV_ItemSelectionChanged(object sender, ListViewItemSelectionChangedEventArgs e)
        {
            e.Item.Selected = false; // auto deselect Selected items
        }

        private void UsersLV_ColumnWidthChanging(object sender, ColumnWidthChangingEventArgs e)
        {
            e.Cancel = true; // if column width of UsersLV is changing cancel it
            e.NewWidth = UsersLV.Columns[e.ColumnIndex].Width;
        }
    }
}
