namespace TriviaClientGUI
{
    partial class GameResultsWin
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(GameResultsWin));
            this.ResultsLV = new System.Windows.Forms.ListView();
            this.Userame = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.Score = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.AvargeTime = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.CloseBTN = new System.Windows.Forms.Button();
            this.ErrorLBL = new System.Windows.Forms.Label();
            this.timer = new System.Windows.Forms.Timer(this.components);
            this.WinnerLBL = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // ResultsLV
            // 
            this.ResultsLV.Alignment = System.Windows.Forms.ListViewAlignment.Default;
            this.ResultsLV.BackColor = System.Drawing.Color.SeaShell;
            this.ResultsLV.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.Userame,
            this.Score,
            this.AvargeTime});
            this.ResultsLV.FullRowSelect = true;
            this.ResultsLV.HeaderStyle = System.Windows.Forms.ColumnHeaderStyle.Nonclickable;
            this.ResultsLV.HideSelection = false;
            this.ResultsLV.Location = new System.Drawing.Point(12, 12);
            this.ResultsLV.MultiSelect = false;
            this.ResultsLV.Name = "ResultsLV";
            this.ResultsLV.RightToLeftLayout = true;
            this.ResultsLV.Size = new System.Drawing.Size(395, 152);
            this.ResultsLV.TabIndex = 83;
            this.ResultsLV.UseCompatibleStateImageBehavior = false;
            this.ResultsLV.View = System.Windows.Forms.View.Details;
            this.ResultsLV.ColumnWidthChanging += new System.Windows.Forms.ColumnWidthChangingEventHandler(this.ResultsLV_ColumnWidthChanging);
            // 
            // Userame
            // 
            this.Userame.Text = "Userame";
            this.Userame.Width = 156;
            // 
            // Score
            // 
            this.Score.Text = "Score";
            this.Score.Width = 109;
            // 
            // AvargeTime
            // 
            this.AvargeTime.Text = "Avarge Time";
            this.AvargeTime.Width = 125;
            // 
            // CloseBTN
            // 
            this.CloseBTN.BackColor = System.Drawing.Color.Tomato;
            this.CloseBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.CloseBTN.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Bold);
            this.CloseBTN.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.CloseBTN.Location = new System.Drawing.Point(151, 197);
            this.CloseBTN.Name = "CloseBTN";
            this.CloseBTN.Size = new System.Drawing.Size(95, 40);
            this.CloseBTN.TabIndex = 90;
            this.CloseBTN.Text = "Close";
            this.CloseBTN.UseVisualStyleBackColor = false;
            this.CloseBTN.Click += new System.EventHandler(this.CloseBTN_Click);
            // 
            // ErrorLBL
            // 
            this.ErrorLBL.AutoSize = true;
            this.ErrorLBL.Font = new System.Drawing.Font("Segoe UI", 19.25F, System.Drawing.FontStyle.Bold);
            this.ErrorLBL.Location = new System.Drawing.Point(5, 57);
            this.ErrorLBL.Name = "ErrorLBL";
            this.ErrorLBL.Size = new System.Drawing.Size(420, 72);
            this.ErrorLBL.TabIndex = 91;
            this.ErrorLBL.Text = "Can\'t display the results,\r\nplease wait for everyone to finish";
            this.ErrorLBL.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // timer
            // 
            this.timer.Enabled = true;
            this.timer.Interval = 1000;
            this.timer.Tick += new System.EventHandler(this.Timer_Tick);
            // 
            // WinnerLBL
            // 
            this.WinnerLBL.AutoSize = true;
            this.WinnerLBL.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.WinnerLBL.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Bold);
            this.WinnerLBL.Location = new System.Drawing.Point(12, 167);
            this.WinnerLBL.Name = "WinnerLBL";
            this.WinnerLBL.Size = new System.Drawing.Size(144, 25);
            this.WinnerLBL.TabIndex = 92;
            this.WinnerLBL.Text = "The Winner Is: ";
            this.WinnerLBL.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // GameResultsWin
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Turquoise;
            this.ClientSize = new System.Drawing.Size(419, 249);
            this.Controls.Add(this.WinnerLBL);
            this.Controls.Add(this.ErrorLBL);
            this.Controls.Add(this.CloseBTN);
            this.Controls.Add(this.ResultsLV);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "GameResultsWin";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Game Results";
            this.Load += new System.EventHandler(this.GameResultsWin_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListView ResultsLV;
        private System.Windows.Forms.ColumnHeader Userame;
        private System.Windows.Forms.ColumnHeader Score;
        private System.Windows.Forms.ColumnHeader AvargeTime;
        private System.Windows.Forms.Button CloseBTN;
        private System.Windows.Forms.Label ErrorLBL;
        private System.Windows.Forms.Timer timer;
        private System.Windows.Forms.Label WinnerLBL;
    }
}