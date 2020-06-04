using Newtonsoft.Json;
using System;
using System.Windows.Forms;

namespace TriviaClientGUI
{
    public partial class LoginWin : Form
    {
        public LoginWin()
        {
            InitializeComponent();
        }

        private void LoginBTN_Click(object sender, EventArgs e)
        {
            ErrorProvider.Clear();
            string payload = JsonConvert.SerializeObject(new { Username = UsernameTB.Text, Password = PasswordTB.Text });
            string loginResponse = Client.SendPayload('L', payload); // send login request
            if (loginResponse != "server is dead" && loginResponse != "server has died")
            {
                StatusResponse deserializeLoginResponse = JsonConvert.DeserializeObject<StatusResponse>(loginResponse);
                if (deserializeLoginResponse.Status == 0)
                {
                    ErrorProvider.SetError(LoginBTN, "Invaid login ditails");
                }
                else if (deserializeLoginResponse.Status == 2)
                {
                    ErrorProvider.SetError(LoginBTN, "User already loged in");
                }
                else
                {
                    Properties.Settings.Default.username = UsernameTB.Text; // set the username in the settings
                    MenuWin nextForm = new MenuWin(); // open menu window
                    Hide();
                    nextForm.ShowDialog();
                    Close();
                }
            }
        }

        private void SingupBTN_Click(object sender, EventArgs e)
        {
            SignupWin nextForm = new SignupWin(); // open signup window
            Hide();
            nextForm.ShowDialog();
            Close();
        }
    }
}
