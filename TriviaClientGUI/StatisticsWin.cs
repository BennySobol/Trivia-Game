using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace TriviaClientGUI
{
    public partial class StatisticsWin : Form
    {
        public StatisticsWin()
        {
            InitializeComponent();
        }

        private void StatisticsWin_Load(object sender, EventArgs e)
        {
            RefreshForm();
        }

        private void RefreshForm()
        {
            string loginResponse = Client.SendPayload('T', ""); // send get statistics request
            if (loginResponse == "server has died")
            {
                timer.Stop();
                LoginWin nextForm = new LoginWin(); // logout
                Hide();
                nextForm.ShowDialog();
                Close();
            }
            else if (loginResponse != "server is dead")
            { // display the statistics
                Statistics deserializeStatisticsResponse = JsonConvert.DeserializeObject<Statistics>(loginResponse);
                NumOfGamesTB.Text = deserializeStatisticsResponse.UserStatistics.PlayerGames.ToString();
                AverageTimePerAnsTB.Text = deserializeStatisticsResponse.UserStatistics.AverageAnswerTime.ToString();
                NumOfRightAnsTB.Text = deserializeStatisticsResponse.UserStatistics.CorrectAnswers.ToString();
                NumOfWrongAnsTB.Text = deserializeStatisticsResponse.UserStatistics.WrongAnswers.ToString();

                List<(TextBox, TextBox)> textboxList = new List<(TextBox, TextBox)>
                {
                    (BSName1TB, BSPoint1TB),
                    (BSName2TB, BSPoint2TB),
                    (BSName3TB, BSPoint3TB)
                };
                int index = 0;
                foreach (HighScore highScore in deserializeStatisticsResponse.HighScores) // display the high scores
                {
                    textboxList[index].Item1.Text = highScore.Name.ToString();
                    textboxList[index].Item2.Text = highScore.NumOfCorrectAnswers.ToString();
                    index++;
                }
            }
        }

        private void BackToMenuBTN_Click(object sender, EventArgs e)
        {
            MenuWin nextForm = new MenuWin(); // go back to the menu widows
            Hide();
            nextForm.ShowDialog();
            Close();
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            RefreshForm();
        }
    }
}
