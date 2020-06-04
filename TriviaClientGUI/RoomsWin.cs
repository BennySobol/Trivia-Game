using Newtonsoft.Json;
using System;
using System.Windows.Forms;

namespace TriviaClientGUI
{
    public partial class RoomsWin : Form
    {
        public RoomsWin()
        {
            InitializeComponent();
        }

        private void BackToMenuBTN_Click(object sender, EventArgs e)
        {
            MenuWin nextForm = new MenuWin(); // go back to the menu
            Hide();
            nextForm.ShowDialog();
            Close();
        }

        private void RoomsWin_Load(object sender, EventArgs e)
        {
            RefreshForm();
        }

        private void RefreshForm()
        {
            string getRoomsResponse = Client.SendPayload('G', ""); // send get rooms request
            if (getRoomsResponse == "server has died")
            {
                LoginWin nextForm = new LoginWin(); // logout
                Hide();
                nextForm.ShowDialog();
                Close();
            }
            else if (getRoomsResponse != "server is dead")
            {
                GetRooms deserializegetRoomsResponse = JsonConvert.DeserializeObject<GetRooms>(getRoomsResponse);
                if (deserializegetRoomsResponse.Status == 1)
                {
                    RoomsLV.Items.Clear();
                    foreach (Room room in deserializegetRoomsResponse.Rooms) // display rooms
                    {
                        ListViewItem item = new ListViewItem(room.RoomName);
                        item.SubItems.Add(room.CreatedBy);
                        item.SubItems.Add(room.RoomId.ToString());
                        RoomsLV.Items.Add(item);
                    }
                }
            }
        }

        private void JoinRoomBTN_Click(object sender, EventArgs e)
        {
            try
            {
                ErrorProvider.Clear();
                string payload = JsonConvert.SerializeObject(new { RoomId = RoomsLV.SelectedItems[0].SubItems[2].Text });
                string joinRoomResponse = Client.SendPayload('J', payload); // send join room request
                if (joinRoomResponse == "server has died")
                {
                    LoginWin nextForm = new LoginWin(); // logout
                    Hide();
                    nextForm.ShowDialog();
                    Close();
                }
                else if (joinRoomResponse != "server is dead")
                {
                    StatusResponse deserializejoinRoomResponse = JsonConvert.DeserializeObject<StatusResponse>(joinRoomResponse);
                    if (deserializejoinRoomResponse.Status == 1) // if you can join go to the wating for game room
                    {
                        WaitForGameWin nextForm = new WaitForGameWin(false, RoomsLV.SelectedItems[0].SubItems[0].Text);
                        Hide();
                        nextForm.ShowDialog();
                        Close();
                    }
                    else
                    {
                        ErrorProvider.SetError(JoinRoomBTN, "Room is full"); // the room is full and you can't join
                    }
                }
           }
           catch { } // catch if the selected index is null
        }

        private void RoomsLV_ColumnWidthChanging(object sender, ColumnWidthChangingEventArgs e)
        {
            e.Cancel = true; // if column width of RoomsLV is changing cancel it
            e.NewWidth = RoomsLV.Columns[e.ColumnIndex].Width;
        }

        private void RoomsLV_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                string payload = JsonConvert.SerializeObject(new { RoomId = RoomsLV.SelectedItems[0].SubItems[2].Text });
                string getPlayersInRoomResponse = Client.SendPayload('P', payload); // send get players in a room request
                if (getPlayersInRoomResponse == "server has died")
                {
                    LoginWin nextForm = new LoginWin(); // logout
                    Hide();
                    nextForm.ShowDialog();
                    Close();
                }
                else if (getPlayersInRoomResponse != "server is dead")
                {
                    GetPlayersInRoom deserializeGetPlayersInRoomResponse = JsonConvert.DeserializeObject<GetPlayersInRoom>(getPlayersInRoomResponse);
                    UsersLV.Items.Clear();
                    foreach (Player player in deserializeGetPlayersInRoomResponse.PlayersInRoom) // display players in a room
                    {
                        UsersLV.Items.Add(new ListViewItem(player.PlayerName));
                    }
                }
            }
            catch { } // catch if the selected index is null
        }

        private void UsersLV_ColumnWidthChanging(object sender, ColumnWidthChangingEventArgs e)
        {
            e.Cancel = true; // if column width of UsersLV is changing cancel it
            e.NewWidth = UsersLV.Columns[e.ColumnIndex].Width;
        }

        private void RefreshBTN_Click(object sender, EventArgs e)
        {
            RefreshForm(); // refresh the window
        }

        private void UsersLV_ItemSelectionChanged(object sender, ListViewItemSelectionChangedEventArgs e)
        {
            e.Item.Selected = false; // auto deselect Selected items
        }
    }
}
