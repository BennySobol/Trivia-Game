namespace TriviaClientGUI
{
    partial class MenuWin
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MenuWin));
            this.StatisticsBTN = new System.Windows.Forms.Button();
            this.JoinRoomBTN = new System.Windows.Forms.Button();
            this.CreateRoomBTN = new System.Windows.Forms.Button();
            this.LogoutBTN = new System.Windows.Forms.Button();
            this.ErrorProvider = new System.Windows.Forms.ErrorProvider(this.components);
            this.HelloLBL = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.panel2 = new System.Windows.Forms.Panel();
            this.panel3 = new System.Windows.Forms.Panel();
            this.pictureBox = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.ErrorProvider)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).BeginInit();
            this.SuspendLayout();
            // 
            // StatisticsBTN
            // 
            this.StatisticsBTN.BackColor = System.Drawing.Color.LightSeaGreen;
            this.StatisticsBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.StatisticsBTN.Font = new System.Drawing.Font("Segoe UI", 20F, System.Drawing.FontStyle.Bold);
            this.StatisticsBTN.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.StatisticsBTN.Location = new System.Drawing.Point(65, 272);
            this.StatisticsBTN.Name = "StatisticsBTN";
            this.StatisticsBTN.Size = new System.Drawing.Size(159, 60);
            this.StatisticsBTN.TabIndex = 20;
            this.StatisticsBTN.Text = "Statistics";
            this.StatisticsBTN.UseVisualStyleBackColor = true;
            this.StatisticsBTN.Click += new System.EventHandler(this.StatisticsBTN_Click);
            // 
            // JoinRoomBTN
            // 
            this.JoinRoomBTN.BackColor = System.Drawing.Color.MediumPurple;
            this.JoinRoomBTN.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.JoinRoomBTN.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.JoinRoomBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.JoinRoomBTN.Font = new System.Drawing.Font("Segoe UI", 20F, System.Drawing.FontStyle.Bold);
            this.JoinRoomBTN.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.JoinRoomBTN.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.JoinRoomBTN.Location = new System.Drawing.Point(246, 272);
            this.JoinRoomBTN.Name = "JoinRoomBTN";
            this.JoinRoomBTN.Size = new System.Drawing.Size(179, 60);
            this.JoinRoomBTN.TabIndex = 19;
            this.JoinRoomBTN.Text = "Join Room";
            this.JoinRoomBTN.UseVisualStyleBackColor = false;
            this.JoinRoomBTN.Click += new System.EventHandler(this.JoinRoomBTN_Click);
            // 
            // CreateRoomBTN
            // 
            this.CreateRoomBTN.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(174)))), ((int)(((byte)(219)))));
            this.CreateRoomBTN.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.CreateRoomBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.CreateRoomBTN.Font = new System.Drawing.Font("Segoe UI", 20F, System.Drawing.FontStyle.Bold);
            this.CreateRoomBTN.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.CreateRoomBTN.Location = new System.Drawing.Point(24, 197);
            this.CreateRoomBTN.Name = "CreateRoomBTN";
            this.CreateRoomBTN.Size = new System.Drawing.Size(264, 60);
            this.CreateRoomBTN.TabIndex = 18;
            this.CreateRoomBTN.Text = "Create New Room";
            this.CreateRoomBTN.UseVisualStyleBackColor = false;
            this.CreateRoomBTN.Click += new System.EventHandler(this.CreateRoomBTN_Click);
            // 
            // LogoutBTN
            // 
            this.LogoutBTN.BackColor = System.Drawing.Color.Tomato;
            this.LogoutBTN.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.LogoutBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.LogoutBTN.Font = new System.Drawing.Font("Segoe UI", 20F, System.Drawing.FontStyle.Bold);
            this.LogoutBTN.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.LogoutBTN.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.LogoutBTN.Location = new System.Drawing.Point(312, 197);
            this.LogoutBTN.Name = "LogoutBTN";
            this.LogoutBTN.Size = new System.Drawing.Size(160, 60);
            this.LogoutBTN.TabIndex = 21;
            this.LogoutBTN.Text = "Logout";
            this.LogoutBTN.UseVisualStyleBackColor = false;
            this.LogoutBTN.Click += new System.EventHandler(this.LogoutBTN_Click);
            // 
            // ErrorProvider
            // 
            this.ErrorProvider.BlinkStyle = System.Windows.Forms.ErrorBlinkStyle.AlwaysBlink;
            this.ErrorProvider.ContainerControl = this;
            // 
            // HelloLBL
            // 
            this.HelloLBL.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.HelloLBL.BackColor = System.Drawing.Color.Teal;
            this.HelloLBL.Font = new System.Drawing.Font("Segoe UI", 21.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.HelloLBL.ForeColor = System.Drawing.SystemColors.Menu;
            this.HelloLBL.Location = new System.Drawing.Point(-3, 0);
            this.HelloLBL.Name = "HelloLBL";
            this.HelloLBL.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.HelloLBL.Size = new System.Drawing.Size(1738, 40);
            this.HelloLBL.TabIndex = 79;
            this.HelloLBL.Text = "Hello Name";
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.Teal;
            this.panel1.Location = new System.Drawing.Point(-134, 353);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(697, 30);
            this.panel1.TabIndex = 81;
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.Color.Teal;
            this.panel2.Location = new System.Drawing.Point(-106, 27);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(112, 339);
            this.panel2.TabIndex = 82;
            // 
            // panel3
            // 
            this.panel3.BackColor = System.Drawing.Color.Teal;
            this.panel3.Location = new System.Drawing.Point(478, 27);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(112, 339);
            this.panel3.TabIndex = 83;
            // 
            // pictureBox
            // 
            this.pictureBox.Image = global::TriviaClientGUI.Properties.Resources.TriviaMenu;
            this.pictureBox.Location = new System.Drawing.Point(12, -153);
            this.pictureBox.Name = "pictureBox";
            this.pictureBox.Size = new System.Drawing.Size(658, 355);
            this.pictureBox.TabIndex = 80;
            this.pictureBox.TabStop = false;
            // 
            // MenuWin
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Turquoise;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.ClientSize = new System.Drawing.Size(484, 361);
            this.Controls.Add(this.panel3);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.HelloLBL);
            this.Controls.Add(this.LogoutBTN);
            this.Controls.Add(this.StatisticsBTN);
            this.Controls.Add(this.JoinRoomBTN);
            this.Controls.Add(this.CreateRoomBTN);
            this.Controls.Add(this.pictureBox);
            this.DoubleBuffered = true;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "MenuWin";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Menu";
            this.Load += new System.EventHandler(this.MenuWin_Load);
            ((System.ComponentModel.ISupportInitialize)(this.ErrorProvider)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button StatisticsBTN;
        private System.Windows.Forms.Button JoinRoomBTN;
        private System.Windows.Forms.Button CreateRoomBTN;
        private System.Windows.Forms.Button LogoutBTN;
        private System.Windows.Forms.ErrorProvider ErrorProvider;
        private System.Windows.Forms.Label HelloLBL;
        private System.Windows.Forms.PictureBox pictureBox;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Panel panel1;
    }
}