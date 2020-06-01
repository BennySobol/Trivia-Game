namespace TriviaClientGUI
{
    partial class WaitForGameWin
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
            this.UsersLV = new System.Windows.Forms.ListView();
            this.UserName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.label1 = new System.Windows.Forms.Label();
            this.StartGameBTN = new System.Windows.Forms.Button();
            this.CloseGameBTN = new System.Windows.Forms.Button();
            this.ErrorProvider = new System.Windows.Forms.ErrorProvider(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.ErrorProvider)).BeginInit();
            this.SuspendLayout();
            // 
            // UsersLV
            // 
            this.UsersLV.Alignment = System.Windows.Forms.ListViewAlignment.Default;
            this.UsersLV.BackColor = System.Drawing.Color.SeaShell;
            this.UsersLV.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.UserName});
            this.UsersLV.FullRowSelect = true;
            this.UsersLV.HideSelection = false;
            this.UsersLV.Location = new System.Drawing.Point(90, 37);
            this.UsersLV.Name = "UsersLV";
            this.UsersLV.RightToLeftLayout = true;
            this.UsersLV.Size = new System.Drawing.Size(164, 246);
            this.UsersLV.TabIndex = 86;
            this.UsersLV.UseCompatibleStateImageBehavior = false;
            this.UsersLV.View = System.Windows.Forms.View.Details;
            // 
            // UserName
            // 
            this.UserName.Text = "User Name";
            this.UserName.Width = 159;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(90, 9);
            this.label1.Name = "label1";
            this.label1.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.label1.Size = new System.Drawing.Size(127, 25);
            this.label1.TabIndex = 85;
            this.label1.Text = "users in room";
            this.label1.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // StartGameBTN
            // 
            this.StartGameBTN.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(174)))), ((int)(((byte)(219)))));
            this.StartGameBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.StartGameBTN.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Bold);
            this.StartGameBTN.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.StartGameBTN.Location = new System.Drawing.Point(260, 197);
            this.StartGameBTN.Name = "StartGameBTN";
            this.StartGameBTN.Size = new System.Drawing.Size(132, 40);
            this.StartGameBTN.TabIndex = 87;
            this.StartGameBTN.Text = "Start Game";
            this.StartGameBTN.UseVisualStyleBackColor = false;
            this.StartGameBTN.Click += new System.EventHandler(this.StartGameBTN_Click);
            // 
            // CloseGameBTN
            // 
            this.CloseGameBTN.BackColor = System.Drawing.Color.Tomato;
            this.CloseGameBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.CloseGameBTN.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Bold);
            this.CloseGameBTN.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.CloseGameBTN.Location = new System.Drawing.Point(260, 243);
            this.CloseGameBTN.Name = "CloseGameBTN";
            this.CloseGameBTN.Size = new System.Drawing.Size(132, 40);
            this.CloseGameBTN.TabIndex = 88;
            this.CloseGameBTN.Text = "Close Game";
            this.CloseGameBTN.UseVisualStyleBackColor = false;
            this.CloseGameBTN.Click += new System.EventHandler(this.CloseGameBTN_Click);
            // 
            // ErrorProvider
            // 
            this.ErrorProvider.BlinkStyle = System.Windows.Forms.ErrorBlinkStyle.AlwaysBlink;
            this.ErrorProvider.ContainerControl = this;
            // 
            // WaitForGameWin
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Turquoise;
            this.ClientSize = new System.Drawing.Size(484, 361);
            this.Controls.Add(this.CloseGameBTN);
            this.Controls.Add(this.StartGameBTN);
            this.Controls.Add(this.UsersLV);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Name = "WaitForGameWin";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Wait For Game";
            this.Load += new System.EventHandler(this.WaitForGameWin_Load);
            ((System.ComponentModel.ISupportInitialize)(this.ErrorProvider)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListView UsersLV;
        private System.Windows.Forms.ColumnHeader UserName;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button StartGameBTN;
        private System.Windows.Forms.Button CloseGameBTN;
        private System.Windows.Forms.ErrorProvider ErrorProvider;
    }
}