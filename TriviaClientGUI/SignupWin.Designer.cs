namespace TriviaClientGUI
{
    partial class SignupWin
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(SignupWin));
            this.SignupBTN = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.AddressTB = new System.Windows.Forms.TextBox();
            this.PhoneTB = new System.Windows.Forms.MaskedTextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.MailTB = new System.Windows.Forms.TextBox();
            this.PasswordTB = new System.Windows.Forms.TextBox();
            this.UsernameTB = new System.Windows.Forms.TextBox();
            this.ErrorProvider = new System.Windows.Forms.ErrorProvider(this.components);
            this.label2 = new System.Windows.Forms.Label();
            this.LoginBTN = new System.Windows.Forms.Button();
            this.BirthdateTB = new System.Windows.Forms.MaskedTextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.ErrorProvider)).BeginInit();
            this.SuspendLayout();
            // 
            // SignupBTN
            // 
            this.SignupBTN.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(174)))), ((int)(((byte)(219)))));
            this.SignupBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.SignupBTN.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Bold);
            this.SignupBTN.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.SignupBTN.Location = new System.Drawing.Point(314, 176);
            this.SignupBTN.Name = "SignupBTN";
            this.SignupBTN.Size = new System.Drawing.Size(99, 40);
            this.SignupBTN.TabIndex = 15;
            this.SignupBTN.Text = "Singup";
            this.SignupBTN.UseVisualStyleBackColor = false;
            this.SignupBTN.Click += new System.EventHandler(this.SignupBTN_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(39, 127);
            this.label3.Name = "label3";
            this.label3.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.label3.Size = new System.Drawing.Size(134, 25);
            this.label3.TabIndex = 60;
            this.label3.Text = "Home Address";
            this.label3.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(39, 159);
            this.label7.Name = "label7";
            this.label7.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.label7.Size = new System.Drawing.Size(66, 25);
            this.label7.TabIndex = 59;
            this.label7.Text = "Phone";
            this.label7.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // AddressTB
            // 
            this.AddressTB.BackColor = System.Drawing.Color.SeaShell;
            this.AddressTB.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.AddressTB.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.AddressTB.Location = new System.Drawing.Point(174, 130);
            this.AddressTB.MaxLength = 25;
            this.AddressTB.Name = "AddressTB";
            this.AddressTB.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.AddressTB.Size = new System.Drawing.Size(250, 26);
            this.AddressTB.TabIndex = 56;
            this.AddressTB.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.TB_KeyPress);
            // 
            // PhoneTB
            // 
            this.PhoneTB.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.PhoneTB.BackColor = System.Drawing.Color.SeaShell;
            this.PhoneTB.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.PhoneTB.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.PhoneTB.Location = new System.Drawing.Point(174, 162);
            this.PhoneTB.Mask = "000-000-0000";
            this.PhoneTB.Name = "PhoneTB";
            this.PhoneTB.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.PhoneTB.Size = new System.Drawing.Size(109, 26);
            this.PhoneTB.TabIndex = 55;
            this.PhoneTB.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.TB_KeyPress);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(39, 95);
            this.label6.Name = "label6";
            this.label6.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.label6.Size = new System.Drawing.Size(121, 25);
            this.label6.TabIndex = 53;
            this.label6.Text = "Mail Address";
            this.label6.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(39, 31);
            this.label4.Name = "label4";
            this.label4.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.label4.Size = new System.Drawing.Size(97, 25);
            this.label4.TabIndex = 52;
            this.label4.Text = "Username";
            this.label4.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(39, 63);
            this.label1.Name = "label1";
            this.label1.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.label1.Size = new System.Drawing.Size(91, 25);
            this.label1.TabIndex = 51;
            this.label1.Text = "Password";
            this.label1.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // MailTB
            // 
            this.MailTB.BackColor = System.Drawing.Color.SeaShell;
            this.MailTB.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.MailTB.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.MailTB.Location = new System.Drawing.Point(174, 98);
            this.MailTB.MaxLength = 25;
            this.MailTB.Name = "MailTB";
            this.MailTB.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.MailTB.Size = new System.Drawing.Size(250, 26);
            this.MailTB.TabIndex = 61;
            this.MailTB.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.TB_KeyPress);
            // 
            // PasswordTB
            // 
            this.PasswordTB.BackColor = System.Drawing.Color.SeaShell;
            this.PasswordTB.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.PasswordTB.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.PasswordTB.Location = new System.Drawing.Point(174, 66);
            this.PasswordTB.MaxLength = 25;
            this.PasswordTB.Name = "PasswordTB";
            this.PasswordTB.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.PasswordTB.Size = new System.Drawing.Size(250, 26);
            this.PasswordTB.TabIndex = 62;
            this.PasswordTB.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.TB_KeyPress);
            // 
            // UsernameTB
            // 
            this.UsernameTB.BackColor = System.Drawing.Color.SeaShell;
            this.UsernameTB.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.UsernameTB.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.UsernameTB.Location = new System.Drawing.Point(174, 34);
            this.UsernameTB.MaxLength = 25;
            this.UsernameTB.Name = "UsernameTB";
            this.UsernameTB.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.UsernameTB.Size = new System.Drawing.Size(250, 26);
            this.UsernameTB.TabIndex = 63;
            this.UsernameTB.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.TB_KeyPress);
            // 
            // ErrorProvider
            // 
            this.ErrorProvider.BlinkStyle = System.Windows.Forms.ErrorBlinkStyle.AlwaysBlink;
            this.ErrorProvider.ContainerControl = this;
            // 
            // label2
            // 
            this.label2.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Segoe UI", 16.25F, System.Drawing.FontStyle.Bold);
            this.label2.Location = new System.Drawing.Point(323, 276);
            this.label2.Name = "label2";
            this.label2.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.label2.Size = new System.Drawing.Size(140, 30);
            this.label2.TabIndex = 80;
            this.label2.Text = "Registered ?";
            // 
            // LoginBTN
            // 
            this.LoginBTN.BackColor = System.Drawing.Color.LightSeaGreen;
            this.LoginBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.LoginBTN.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Bold);
            this.LoginBTN.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.LoginBTN.Location = new System.Drawing.Point(366, 309);
            this.LoginBTN.Name = "LoginBTN";
            this.LoginBTN.Size = new System.Drawing.Size(106, 40);
            this.LoginBTN.TabIndex = 79;
            this.LoginBTN.Text = "Login";
            this.LoginBTN.UseVisualStyleBackColor = true;
            this.LoginBTN.Click += new System.EventHandler(this.LoginBTN_Click);
            // 
            // BirthdateTB
            // 
            this.BirthdateTB.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.BirthdateTB.BackColor = System.Drawing.Color.SeaShell;
            this.BirthdateTB.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.BirthdateTB.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.BirthdateTB.Location = new System.Drawing.Point(174, 194);
            this.BirthdateTB.Mask = "00/00/0000";
            this.BirthdateTB.Name = "BirthdateTB";
            this.BirthdateTB.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.BirthdateTB.Size = new System.Drawing.Size(109, 26);
            this.BirthdateTB.TabIndex = 81;
            this.BirthdateTB.ValidatingType = typeof(System.DateTime);
            this.BirthdateTB.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.TB_KeyPress);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(39, 191);
            this.label5.Name = "label5";
            this.label5.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.label5.Size = new System.Drawing.Size(89, 25);
            this.label5.TabIndex = 82;
            this.label5.Text = "Birthdate";
            this.label5.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Segoe UI", 19F);
            this.label8.ForeColor = System.Drawing.Color.Red;
            this.label8.Location = new System.Drawing.Point(430, 34);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(26, 36);
            this.label8.TabIndex = 83;
            this.label8.Text = "*";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Segoe UI", 19F);
            this.label9.ForeColor = System.Drawing.Color.Red;
            this.label9.Location = new System.Drawing.Point(430, 63);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(26, 36);
            this.label9.TabIndex = 84;
            this.label9.Text = "*";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Segoe UI", 19F);
            this.label10.ForeColor = System.Drawing.Color.Red;
            this.label10.Location = new System.Drawing.Point(430, 98);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(26, 36);
            this.label10.TabIndex = 85;
            this.label10.Text = "*";
            // 
            // SignupWin
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Turquoise;
            this.ClientSize = new System.Drawing.Size(484, 361);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.BirthdateTB);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.LoginBTN);
            this.Controls.Add(this.UsernameTB);
            this.Controls.Add(this.PasswordTB);
            this.Controls.Add(this.MailTB);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.AddressTB);
            this.Controls.Add(this.PhoneTB);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.SignupBTN);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "SignupWin";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Signup";
            this.Load += new System.EventHandler(this.SignupWin_Load);
            ((System.ComponentModel.ISupportInitialize)(this.ErrorProvider)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button SignupBTN;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label7;
        protected internal System.Windows.Forms.TextBox AddressTB;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label1;
        protected internal System.Windows.Forms.TextBox MailTB;
        protected internal System.Windows.Forms.TextBox PasswordTB;
        protected internal System.Windows.Forms.TextBox UsernameTB;
        private System.Windows.Forms.ErrorProvider ErrorProvider;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button LoginBTN;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.MaskedTextBox BirthdateTB;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label8;
        protected internal System.Windows.Forms.MaskedTextBox PhoneTB;
    }
}