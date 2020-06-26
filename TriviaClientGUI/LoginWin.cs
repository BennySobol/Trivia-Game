using Newtonsoft.Json;
using System;
using System.Text;
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

        private void TB_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (Encoding.UTF8.GetByteCount(new char[] { e.KeyChar }) > 1)
            {
                e.Handled = true;
            }
        }

        private void LoginWin_Load(object sender, EventArgs e)
        {
            MaximizeBox = false;
        }

        private void LoginTB_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                LoginBTN.PerformClick();
            }
        }
    }
}
