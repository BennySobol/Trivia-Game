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
    public partial class GameResultsWin : Form
    {
        public GameResultsWin()
        {
            InitializeComponent();
        }

        private void GameResultsWin_Load(object sender, EventArgs e)
        {
            MaximizeBox = false;
            WinnerLBL.Visible = false;
            ResultsLV.Visible = false;
            RefreshForm();
        }

        private void RefreshForm()
        {
            try
            {
                string getGameResults = Client.SendPayload('R', ""); // send get results request
                if (getGameResults == "server has died")
                {
                    timer.Stop();
                    LoginWin nextForm = new LoginWin(); // logout
                    Hide();
                    nextForm.ShowDialog();
                    Close();
                }
                else if (getGameResults != "server is dead")
                {  // display the results
                    GetGameResults deserializeGetGameResultsResponse = JsonConvert.DeserializeObject<GetGameResults>(getGameResults);
                    if (deserializeGetGameResultsResponse.Status == 1)
                    {
                        timer.Stop();
                        int max = 0;
                        string winner = "";
                        WinnerLBL.Visible = true;
                        ResultsLV.Visible = true;
                        ErrorLBL.Visible = false;
                        foreach (Result result in deserializeGetGameResultsResponse.Results)
                        {
                            if (max <= result.CorrectAnswerCount)
                            {
                                winner = result.Username;
                            }
                            ListViewItem item = new ListViewItem(result.Username);
                            item.SubItems.Add(result.CorrectAnswerCount.ToString() + "/" + (result.WrongAnswerCount + result.CorrectAnswerCount).ToString());
                            item.SubItems.Add(result.AverageAnswerTime.ToString());
                            ResultsLV.Items.Add(item);
                        }
                        WinnerLBL.Text = "The Winner Is: " + winner;
                    }
                }
            }
            catch { } // will catch error responce from the server
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            RefreshForm();
        }

        private void CloseBTN_Click(object sender, EventArgs e)
        {
            timer.Stop();
            Close();
        }

        private void ResultsLV_ColumnWidthChanging(object sender, ColumnWidthChangingEventArgs e)
        {
            e.Cancel = true; // if column width of ResultsLV is changing cancel it
            e.NewWidth = ResultsLV.Columns[e.ColumnIndex].Width;
        }
    }
}
