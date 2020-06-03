namespace TriviaClientGUI
{
    partial class CreateRoomWin
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
            this.RoomNameTB = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.CreateRoomBTN = new System.Windows.Forms.Button();
            this.MaxUsersNUD = new System.Windows.Forms.NumericUpDown();
            this.QuestionCountNUD = new System.Windows.Forms.NumericUpDown();
            this.AnswerTimeoutNUD = new System.Windows.Forms.NumericUpDown();
            this.BackToMenuBTN = new System.Windows.Forms.Button();
            this.ErrorProvider = new System.Windows.Forms.ErrorProvider(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.MaxUsersNUD)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.QuestionCountNUD)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.AnswerTimeoutNUD)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ErrorProvider)).BeginInit();
            this.SuspendLayout();
            // 
            // RoomNameTB
            // 
            this.RoomNameTB.BackColor = System.Drawing.Color.SeaShell;
            this.RoomNameTB.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.RoomNameTB.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.RoomNameTB.Location = new System.Drawing.Point(192, 44);
            this.RoomNameTB.MaxLength = 20;
            this.RoomNameTB.Name = "RoomNameTB";
            this.RoomNameTB.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.RoomNameTB.Size = new System.Drawing.Size(217, 26);
            this.RoomNameTB.TabIndex = 74;
            this.RoomNameTB.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(80, 105);
            this.label3.Name = "label3";
            this.label3.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.label3.Size = new System.Drawing.Size(195, 25);
            this.label3.TabIndex = 71;
            this.label3.Text = "Number Of Questions";
            this.label3.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(80, 137);
            this.label6.Name = "label6";
            this.label6.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.label6.Size = new System.Drawing.Size(253, 25);
            this.label6.TabIndex = 67;
            this.label6.Text = "Time Per Question (Seconds)";
            this.label6.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(80, 42);
            this.label4.Name = "label4";
            this.label4.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.label4.Size = new System.Drawing.Size(115, 25);
            this.label4.TabIndex = 66;
            this.label4.Text = "Room Name";
            this.label4.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(77, 73);
            this.label1.Name = "label1";
            this.label1.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.label1.Size = new System.Drawing.Size(260, 25);
            this.label1.TabIndex = 65;
            this.label1.Text = "Maximum Number Of Players";
            this.label1.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // CreateRoomBTN
            // 
            this.CreateRoomBTN.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(174)))), ((int)(((byte)(219)))));
            this.CreateRoomBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.CreateRoomBTN.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Bold);
            this.CreateRoomBTN.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.CreateRoomBTN.Location = new System.Drawing.Point(182, 190);
            this.CreateRoomBTN.Name = "CreateRoomBTN";
            this.CreateRoomBTN.Size = new System.Drawing.Size(143, 40);
            this.CreateRoomBTN.TabIndex = 64;
            this.CreateRoomBTN.Text = "Create Room";
            this.CreateRoomBTN.UseVisualStyleBackColor = false;
            this.CreateRoomBTN.Click += new System.EventHandler(this.CreateRoomBTN_Click);
            // 
            // MaxUsersNUD
            // 
            this.MaxUsersNUD.BackColor = System.Drawing.Color.SeaShell;
            this.MaxUsersNUD.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.MaxUsersNUD.Font = new System.Drawing.Font("Arial", 12F);
            this.MaxUsersNUD.Location = new System.Drawing.Point(343, 76);
            this.MaxUsersNUD.Maximum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.MaxUsersNUD.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.MaxUsersNUD.Name = "MaxUsersNUD";
            this.MaxUsersNUD.Size = new System.Drawing.Size(66, 26);
            this.MaxUsersNUD.TabIndex = 75;
            this.MaxUsersNUD.Tag = "";
            this.MaxUsersNUD.Value = new decimal(new int[] {
            5,
            0,
            0,
            0});
            // 
            // QuestionCountNUD
            // 
            this.QuestionCountNUD.BackColor = System.Drawing.Color.SeaShell;
            this.QuestionCountNUD.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.QuestionCountNUD.Font = new System.Drawing.Font("Arial", 12F);
            this.QuestionCountNUD.Location = new System.Drawing.Point(343, 108);
            this.QuestionCountNUD.Maximum = new decimal(new int[] {
            50,
            0,
            0,
            0});
            this.QuestionCountNUD.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.QuestionCountNUD.Name = "QuestionCountNUD";
            this.QuestionCountNUD.Size = new System.Drawing.Size(66, 26);
            this.QuestionCountNUD.TabIndex = 76;
            this.QuestionCountNUD.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            // 
            // AnswerTimeoutNUD
            // 
            this.AnswerTimeoutNUD.BackColor = System.Drawing.Color.SeaShell;
            this.AnswerTimeoutNUD.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.AnswerTimeoutNUD.Font = new System.Drawing.Font("Arial", 12F);
            this.AnswerTimeoutNUD.Location = new System.Drawing.Point(343, 140);
            this.AnswerTimeoutNUD.Maximum = new decimal(new int[] {
            60,
            0,
            0,
            0});
            this.AnswerTimeoutNUD.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.AnswerTimeoutNUD.Name = "AnswerTimeoutNUD";
            this.AnswerTimeoutNUD.Size = new System.Drawing.Size(66, 26);
            this.AnswerTimeoutNUD.TabIndex = 77;
            this.AnswerTimeoutNUD.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            // 
            // BackToMenuBTN
            // 
            this.BackToMenuBTN.BackColor = System.Drawing.Color.MediumPurple;
            this.BackToMenuBTN.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.BackToMenuBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.BackToMenuBTN.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Bold);
            this.BackToMenuBTN.ForeColor = System.Drawing.Color.Transparent;
            this.BackToMenuBTN.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.BackToMenuBTN.Location = new System.Drawing.Point(425, 5);
            this.BackToMenuBTN.Name = "BackToMenuBTN";
            this.BackToMenuBTN.Size = new System.Drawing.Size(55, 27);
            this.BackToMenuBTN.TabIndex = 81;
            this.BackToMenuBTN.Text = "Back";
            this.BackToMenuBTN.UseVisualStyleBackColor = false;
            this.BackToMenuBTN.Click += new System.EventHandler(this.BackToMenuBTN_Click);
            // 
            // ErrorProvider
            // 
            this.ErrorProvider.BlinkStyle = System.Windows.Forms.ErrorBlinkStyle.AlwaysBlink;
            this.ErrorProvider.ContainerControl = this;
            // 
            // CreateRoomWin
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Turquoise;
            this.ClientSize = new System.Drawing.Size(484, 361);
            this.Controls.Add(this.BackToMenuBTN);
            this.Controls.Add(this.AnswerTimeoutNUD);
            this.Controls.Add(this.QuestionCountNUD);
            this.Controls.Add(this.MaxUsersNUD);
            this.Controls.Add(this.RoomNameTB);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.CreateRoomBTN);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Name = "CreateRoomWin";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Create new room";
            this.Load += new System.EventHandler(this.CreateRoomWin_Load);
            ((System.ComponentModel.ISupportInitialize)(this.MaxUsersNUD)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.QuestionCountNUD)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.AnswerTimeoutNUD)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ErrorProvider)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        protected internal System.Windows.Forms.TextBox RoomNameTB;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button CreateRoomBTN;
        private System.Windows.Forms.NumericUpDown MaxUsersNUD;
        private System.Windows.Forms.NumericUpDown QuestionCountNUD;
        private System.Windows.Forms.NumericUpDown AnswerTimeoutNUD;
        private System.Windows.Forms.Button BackToMenuBTN;
        private System.Windows.Forms.ErrorProvider ErrorProvider;
    }
}