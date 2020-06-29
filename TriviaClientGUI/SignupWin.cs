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
    public partial class SignupWin : Form
    {
        public SignupWin()
        {
            InitializeComponent();
        }

        private void LoginBTN_Click(object sender, EventArgs e)
        {
            LoginWin nextForm = new LoginWin(); // open login window
            Hide();
            nextForm.ShowDialog();
            Close();
        }

        private void SignupBTN_Click(object sender, EventArgs e)
        {
            string phone = PhoneTB.Text.Trim(), birthdate = BirthdateTB.Text.Trim();
            if (phone == "-   -") // if phone is empty
            {
                phone = "";
            }
            if (birthdate == "/  /") // if birthdate is empty
            {
                birthdate = "";
            }
            ErrorProvider.Clear();
            string payload = JsonConvert.SerializeObject(new { Username = UsernameTB.Text.Trim(), Password = PasswordTB.Text.Trim(), Email = MailTB.Text.Trim(), Phone = phone, Address = AddressTB.Text.Trim(), BirthDate = birthdate });
            string loginResponse = Client.SendPayload('S', payload, false);
            if (loginResponse != "server is dead" && loginResponse != "server has died")
            {
                StatusResponse deserializeLoginResponse = JsonConvert.DeserializeObject<StatusResponse>(loginResponse);
                switch(deserializeLoginResponse.Status)
                {
                    case 0:
                        ErrorProvider.SetError(SignupBTN, "Error, The database fails to add the user");
                        break;
                    case 1:
                        Properties.Settings.Default.username = UsernameTB.Text; // If the user is added to the database open menu win
                        MenuWin nextForm = new MenuWin();
                        Hide();
                        nextForm.ShowDialog();
                        Close();
                        break;
                    case 2:
                        ErrorProvider.SetError(UsernameTB, "Username already exists");
                        break;
                    case 3:
                        ErrorProvider.SetError(MailTB, "Email already exists");
                        break;
                    case 4:
                        ErrorProvider.SetError(UsernameTB, "Invaid username!\nThe username needs to start with letter and be longer the 4 characters");
                        break;
                    case 5:
                        ErrorProvider.SetError(PasswordTB, "Invaid password!\nThe password needs to be more then 7 characters, with at least one - spashial charcter{#!@$%^&*}, digit, upper letter and a lower letter");
                        break;
                    case 6:
                        ErrorProvider.SetError(MailTB, "Invaid email!\nThe format is XXXX@XXX.XX(.XXX)...");
                        break;
                    case 7:
                        ErrorProvider.SetError(PhoneTB, "Invaid phone!\nThe format is {0XX-XXX-XXXX}");
                        break;
                    case 8:
                        ErrorProvider.SetError(AddressTB, "Invaid address!\nThe format is {Street Apt City}, {Street, Apt, City}, {Street, Apt City}, {Street Apt, City}");
                        break;
                    default:
                        ErrorProvider.SetError(BirthdateTB, "Invaid birthdate!\nThe format is {DD/MM/YYYY}");
                        break;
                }
            }
        }

        private void TB_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (Encoding.UTF8.GetByteCount(new char[] { e.KeyChar }) > 1)
            {
                e.Handled = true;
            }
        }

        private void SignupWin_Load(object sender, EventArgs e)
        {
            MaximizeBox = false;
        }
    }
}
