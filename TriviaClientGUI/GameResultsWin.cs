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
            WinnerLBL.Visible = false;
            ResultsLV.Visible = false;
            RefreshForm();
        }

        private void RefreshForm()
        {
            string getGameResults = Client.SendPayload('R', ""); // send get results request
            if (getGameResults == "server has died")
            {
                LoginWin nextForm = new LoginWin(); // logout
                Hide();
                nextForm.ShowDialog();
                Close();
            }
            else if (getGameResults != "server is dead")
            {  // display the results
                timer.Stop();
                GetGameResults deserializeGetGameResultsResponse = JsonConvert.DeserializeObject<GetGameResults>(getGameResults);
                if (deserializeGetGameResultsResponse.Status == 1)
                {
                    timer.Stop();
                    WinnerLBL.Visible = true;
                    ResultsLV.Visible = true;
                    ErrorLBL.Visible = false;
                    foreach(Result result in deserializeGetGameResultsResponse.Results)
                    {
                        ListViewItem item = new ListViewItem(result.Username);
                        item.SubItems.Add(result.CorrectAnswerCount.ToString() +"/"+ (result.WrongAnswerCount+ result.CorrectAnswerCount).ToString());
                        item.SubItems.Add(result.AverageAnswerTime.ToString());
                        ResultsLV.Items.Add(item);
                    }
                }
            }
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
