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
        private int CorrectAnswers = 0;
        private int WrongAnswers = 0;
        public TriviaWin(int QuestionsCount, int TimePerQuestion)
        {
            this.QuestionsCount = QuestionsCount;
            this.TimePerQuestion = TimePerQuestion;
            InitializeComponent();
            GetNewQuestion(QuestionLBL, Ans1BTN, Ans2BTN, Ans3BTN, Ans4BTN, BackToMenuBTN);
        }

        private void Ans1BTN_Click(object sender, EventArgs e)
        {
            SubmitAnswer(Ans1BTN, 0);
        }

        private void Ans2BTN_Click(object sender, EventArgs e)
        {
            SubmitAnswer(Ans2BTN, 1);
        }

        private void Ans3BTN_Click(object sender, EventArgs e)
        {
            SubmitAnswer(Ans3BTN, 2);
        }

        private void Ans4BTN_Click(object sender, EventArgs e)
        {
            SubmitAnswer(Ans4BTN, 3);
        }

        private async void Timer_Tick(object sender, EventArgs e)
        {
            TimeLBL.Text = "Time left: " + CurrentTime.ToString() + " / " + TimePerQuestion.ToString();
            if (CurrentTime == 0 && Ans1BTN.Enabled && Ans2BTN.Enabled && Ans3BTN.Enabled && Ans4BTN.Enabled) // new question
            {
                SubmitAnswer(new Button(), 5); // send wrong answer to the server
                EnabledButtons(false, Ans1BTN, Ans2BTN, Ans3BTN, Ans4BTN, BackToMenuBTN);
                Ans1BTN.BackColor = Color.FromArgb(255, 128, 128);
                Ans2BTN.BackColor = Color.FromArgb(255, 128, 128);
                Ans3BTN.BackColor = Color.FromArgb(255, 128, 128);
                Ans4BTN.BackColor = Color.FromArgb(255, 128, 128);
                await Task.Delay(1000);
                Ans1BTN.BackColor = Color.DarkGray;
                Ans2BTN.BackColor = Color.DarkGray;
                Ans3BTN.BackColor = Color.DarkGray;
                Ans4BTN.BackColor = Color.DarkGray;
                EnabledButtons(true, Ans1BTN, Ans2BTN, Ans3BTN, Ans4BTN, BackToMenuBTN);
            }
            else
            {
                CurrentTime--;
            }
        }

        // this function wiil submit an answer to the server and give a feedback to the clecked Button
        private async void SubmitAnswer(Button AnsBTN, int AnsIndex)
        {
            try
            {
                EnabledButtons(false, Ans1BTN, Ans2BTN, Ans3BTN, Ans4BTN, BackToMenuBTN);
                string payload = JsonConvert.SerializeObject(new { AnswerId = AnsIndex });
                string submitAnswer = Client.SendPayload('B', payload); // send get statistics request
                if (submitAnswer == "server has died")
                {
                    LoginWin nextForm = new LoginWin(); // logout
                    Hide();
                    nextForm.ShowDialog();
                    Close();
                }
                else if (submitAnswer != "server is dead")
                {  // display the question
                    SubmitAnswer deserializeSubmitAnswerResponse = JsonConvert.DeserializeObject<SubmitAnswer>(submitAnswer);

                    if (deserializeSubmitAnswerResponse.IsCorrectAnswer)
                    {
                        CorrectAnsTBL.Text = "Correct Answers: " + (++CorrectAnswers).ToString() + "/" + (WrongAnswers + CorrectAnswers).ToString();
                        AnsBTN.BackColor = Color.FromArgb(128, 255, 128);
                        await Task.Delay(1000);
                        AnsBTN.BackColor = Color.DarkGray;
                        GetNewQuestion(QuestionLBL, Ans1BTN, Ans2BTN, Ans3BTN, Ans4BTN, BackToMenuBTN);
                    }
                    else
                    {
                        CorrectAnsTBL.Text = "Correct Answers: " + CorrectAnswers.ToString() + "/" + (++WrongAnswers + CorrectAnswers).ToString();
                        AnsBTN.BackColor = Color.FromArgb(255, 128, 128);
                        await Task.Delay(1000);
                        AnsBTN.BackColor = Color.DarkGray;
                        GetNewQuestion(QuestionLBL, Ans1BTN, Ans2BTN, Ans3BTN, Ans4BTN, BackToMenuBTN);
                    }
                }
                EnabledButtons(true, Ans1BTN, Ans2BTN, Ans3BTN, Ans4BTN, BackToMenuBTN);
            }
            catch { } // will catch error responce from the server
        }

        // function to enabled / disabled 4 Button
        private void EnabledButtons(bool enabled, Button Ans1BTN, Button Ans2BTN, Button Ans3BTN, Button Ans4BTN, Button BackToMenuBTN)
        {
            Ans1BTN.Enabled = enabled;
            Ans2BTN.Enabled = enabled;
            Ans3BTN.Enabled = enabled;
            Ans4BTN.Enabled = enabled;
            BackToMenuBTN.Enabled = enabled;
        }

        // this function will get a new question ftom the server
        private void GetNewQuestion(Label QuestionLBL, Button Ans1BTN, Button Ans2BTN, Button Ans3BTN, Button Ans4BTN, Button BackToMenuBTN)
        {
            try
            {
                if (++CurrentQuestion == QuestionsCount + 1) // if user finshed the game
                {
                    timer.Stop();
                    GameResultsWin nextForm = new GameResultsWin(); // go back to menu
                    Hide();
                    nextForm.ShowDialog();
                    try
                    {
                        BackToMenuBTN.PerformClick(); // try to leave game - in case the user did not wait
                    }
                    catch { }
                    MenuWin nextNextForm = new MenuWin(); // go back to the menu
                    Hide();
                    nextNextForm.ShowDialog();
                    Close();
                    return;
                }
                string getQuestion = Client.SendPayload('Q', ""); // send get statistics request
                if (getQuestion == "server has died")
                {
                    LoginWin nextForm = new LoginWin(); // display the results
                    Hide();
                    nextForm.ShowDialog();
                    Close();
                }
                else if (getQuestion != "server is dead")
                {  // display the question
                    CurrentTime = TimePerQuestion;
                    TimeLBL.Text = "Time left: " + CurrentTime.ToString() + " / " + TimePerQuestion.ToString();
                    CurrentTime--;
                    GetQuestion deserializeGetQuestionResponse = JsonConvert.DeserializeObject<GetQuestion>(getQuestion);
                    QuestionLBL.Text = WebUtility.HtmlDecode(deserializeGetQuestionResponse.Question);
                    Ans1BTN.Text = WebUtility.HtmlDecode(deserializeGetQuestionResponse.PossibleAnswers[0].Answer);
                    Ans2BTN.Text = WebUtility.HtmlDecode(deserializeGetQuestionResponse.PossibleAnswers[1].Answer);
                    Ans3BTN.Text = WebUtility.HtmlDecode(deserializeGetQuestionResponse.PossibleAnswers[2].Answer);
                    Ans4BTN.Text = WebUtility.HtmlDecode(deserializeGetQuestionResponse.PossibleAnswers[3].Answer);
                }
            }
            catch { } // will catch error responce from the server
        }

        // this function will leave the game and let the server know it
        private void BackToMenuBTN_Click(object sender, EventArgs e)
        {
            timer.Stop();
            ErrorProvider.Clear();
            string leaveRoomResponse = Client.SendPayload('M', ""); // send logout request
            if (leaveRoomResponse == "server has died")
            {
                LoginWin nextForm = new LoginWin(); // logout
                Hide();
                nextForm.ShowDialog();
                Close();
            }
            else if (leaveRoomResponse != "server is dead")
            {
                StatusResponse deserializeLeaveRoomResponse = JsonConvert.DeserializeObject<StatusResponse>(leaveRoomResponse);
                if (deserializeLeaveRoomResponse.Status == 0)
                {
                    ErrorProvider.SetError(BackToMenuBTN, "Error, don't try to hack :)"); // error with leave room, can't happend normaly - just from a script
                }
                else
                {
                    MenuWin nextForm = new MenuWin(); // go back to the menu window
                    Hide();
                    nextForm.ShowDialog();
                    Close();
                }
            }
        }

        private void TriviaWin_Load(object sender, EventArgs e)
        {
            ControlBox = false;
        }
    }
}
