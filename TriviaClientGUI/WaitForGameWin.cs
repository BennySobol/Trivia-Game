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
    public partial class WaitForGameWin : Form
    {
        private readonly bool isCreator;
        private readonly int roomId;

        public int RoomId => roomId;

        public WaitForGameWin(bool isCreator, int roomId)
        {
            this.roomId = roomId;
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
        }

        private void StartGameBTN_Click(object sender, EventArgs e)
        {
            TriviaWin nextForm = new TriviaWin(); // open the trivia window
            Hide();
            nextForm.ShowDialog();
            Close();
        }

        private void CloseGameBTN_Click(object sender, EventArgs e)
        {
            if(isCreator) // close the room
            {

            }
            else // leave the room
            {

            }
        }
    }
}
