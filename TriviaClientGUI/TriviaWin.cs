using Newtonsoft.Json;
using System;
using System.Drawing;
using System.Net;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace TriviaClientGUI
{
    public partial class TriviaWin : Form
    {
        private readonly int QuestionsCount;
        private readonly int TimePerQuestion;
        private int CurrentTime = 0;
        private int CurrentQuestion = 0;
        public TriviaWin(int QuestionsCount, int TimePerQuestion)
        {
            this.QuestionsCount = QuestionsCount;
            this.TimePerQuestion = TimePerQuestion;
            InitializeComponent();
            GetNewQuestion(QuestionLBL, Ans1BTN, Ans2BTN, Ans3BTN, Ans4BTN);
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
                GetNewQuestion(QuestionLBL, Ans1BTN, Ans2BTN, Ans3BTN, Ans4BTN);
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
            {
                CurrentTime--;
            }
        }

        private void GetNewQuestion(Label QuestionLBL, Button Ans1BTN, Button Ans2BTN, Button Ans3BTN, Button Ans4BTN)
        {
            if (++CurrentQuestion == QuestionsCount)
            {
                timer.Stop();
                MessageBox.Show("The Game has Ended");
                return;
            }
            string getQuestion = Client.SendPayload('Q', ""); // send get statistics request
            if (getQuestion == "server has died")
            {
                LoginWin nextForm = new LoginWin(); // logout
                Hide();
                nextForm.ShowDialog();
                Close();
            }
            else if (getQuestion != "server is dead")
            {  // display the question
                GetQuestion deserializeGetQuestionResponse = JsonConvert.DeserializeObject<GetQuestion>(getQuestion);
                QuestionLBL.Text = WebUtility.HtmlDecode(deserializeGetQuestionResponse.Question);
                Ans1BTN.Text = WebUtility.HtmlDecode(deserializeGetQuestionResponse.PossibleAnswers[0].Answer);
                Ans2BTN.Text = WebUtility.HtmlDecode(deserializeGetQuestionResponse.PossibleAnswers[1].Answer);
                Ans3BTN.Text = WebUtility.HtmlDecode(deserializeGetQuestionResponse.PossibleAnswers[2].Answer);
                Ans4BTN.Text = WebUtility.HtmlDecode(deserializeGetQuestionResponse.PossibleAnswers[3].Answer);
            }
        }

        private void BackToMenuBTN_Click(object sender, EventArgs e)
        {

        }
    }
}
