using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace TriviaClientGUI
{
    public partial class TriviaWin : Form
    {
        private readonly int TimePerQuestion = 5;
        private int CurrentTime = 5;
        public TriviaWin()
        {
            InitializeComponent();
        }

        private async void Ans1BTN_Click(object sender, EventArgs e)
        {
            if (Ans1BTN.BackColor == Color.DarkGray)
            {
                Ans1BTN.BackColor = Color.FromArgb(128, 255, 128);
                await Task.Delay(1000);
                Ans1BTN.BackColor = Color.DarkGray;
            }
        }


        private async void Ans2BTN_Click(object sender, EventArgs e)
        {
            if (Ans2BTN.BackColor == Color.DarkGray)
            {
                Ans2BTN.BackColor = Color.FromArgb(128, 255, 128);
                await Task.Delay(1000);
                Ans2BTN.BackColor = Color.DarkGray;
            }
        }

        private async void Ans3BTN_Click(object sender, EventArgs e)
        {
            if (Ans3BTN.BackColor == Color.DarkGray)
            {
                Ans3BTN.BackColor = Color.FromArgb(128, 255, 128);
                await Task.Delay(1000);
                Ans3BTN.BackColor = Color.DarkGray;
            }
        }

        private async void Ans4BTN_Click(object sender, EventArgs e)
        {
            if (Ans4BTN.BackColor == Color.DarkGray)
            {
                Ans4BTN.BackColor = Color.FromArgb(128, 255, 128);
                await Task.Delay(1000);
                Ans4BTN.BackColor = Color.DarkGray;
            }
        }

        private async void Timer_Tick(object sender, EventArgs e)
        {
            TimeLBL.Text = "Time left: " + CurrentTime.ToString() + " / " + TimePerQuestion.ToString();
            if (CurrentTime == 0) // new question
            {
                CurrentTime = TimePerQuestion;
                Ans1BTN.BackColor = Color.FromArgb(255, 128, 128);
                Ans2BTN.BackColor = Color.FromArgb(255, 128, 128);
                Ans3BTN.BackColor = Color.FromArgb(255, 128, 128);
                Ans4BTN.BackColor = Color.FromArgb(255, 128, 128);
                await Task.Delay(1000);
                Ans1BTN.BackColor = Color.DarkGray;
                Ans2BTN.BackColor = Color.DarkGray;
                Ans3BTN.BackColor = Color.DarkGray;
                Ans4BTN.BackColor = Color.DarkGray;
            }
            else
                CurrentTime--;

        }

        private void BackToMenuBTN_Click(object sender, EventArgs e)
        {

        }
    }
}
