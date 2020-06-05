namespace TriviaClientGUI
{
    partial class TriviaWin
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(TriviaWin));
            this.BackToMenuBTN = new System.Windows.Forms.Button();
            this.Ans3BTN = new System.Windows.Forms.Button();
            this.Ans4BTN = new System.Windows.Forms.Button();
            this.Ans2BTN = new System.Windows.Forms.Button();
            this.Ans1BTN = new System.Windows.Forms.Button();
            this.TimeLBL = new System.Windows.Forms.Label();
            this.timer = new System.Windows.Forms.Timer(this.components);
            this.QuestionLBL = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // BackToMenuBTN
            // 
            this.BackToMenuBTN.BackColor = System.Drawing.Color.MediumPurple;
            this.BackToMenuBTN.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.BackToMenuBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.BackToMenuBTN.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Bold);
            this.BackToMenuBTN.ForeColor = System.Drawing.Color.Transparent;
            this.BackToMenuBTN.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.BackToMenuBTN.Location = new System.Drawing.Point(710, 3);
            this.BackToMenuBTN.Name = "BackToMenuBTN";
            this.BackToMenuBTN.Size = new System.Drawing.Size(55, 27);
            this.BackToMenuBTN.TabIndex = 79;
            this.BackToMenuBTN.Text = "Back";
            this.BackToMenuBTN.UseVisualStyleBackColor = false;
            this.BackToMenuBTN.Click += new System.EventHandler(this.BackToMenuBTN_Click);
            // 
            // Ans3BTN
            // 
            this.Ans3BTN.BackColor = System.Drawing.Color.DarkGray;
            this.Ans3BTN.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.Ans3BTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Ans3BTN.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Bold);
            this.Ans3BTN.ForeColor = System.Drawing.Color.Transparent;
            this.Ans3BTN.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.Ans3BTN.Location = new System.Drawing.Point(12, 181);
            this.Ans3BTN.Name = "Ans3BTN";
            this.Ans3BTN.Size = new System.Drawing.Size(744, 27);
            this.Ans3BTN.TabIndex = 80;
            this.Ans3BTN.Text = "Exit";
            this.Ans3BTN.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.Ans3BTN.UseVisualStyleBackColor = false;
            this.Ans3BTN.Click += new System.EventHandler(this.Ans3BTN_Click);
            // 
            // Ans4BTN
            // 
            this.Ans4BTN.BackColor = System.Drawing.Color.DarkGray;
            this.Ans4BTN.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.Ans4BTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Ans4BTN.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Bold);
            this.Ans4BTN.ForeColor = System.Drawing.Color.Transparent;
            this.Ans4BTN.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.Ans4BTN.Location = new System.Drawing.Point(12, 214);
            this.Ans4BTN.Name = "Ans4BTN";
            this.Ans4BTN.Size = new System.Drawing.Size(744, 27);
            this.Ans4BTN.TabIndex = 81;
            this.Ans4BTN.Text = "Exit";
            this.Ans4BTN.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.Ans4BTN.UseVisualStyleBackColor = false;
            this.Ans4BTN.Click += new System.EventHandler(this.Ans4BTN_Click);
            // 
            // Ans2BTN
            // 
            this.Ans2BTN.BackColor = System.Drawing.Color.DarkGray;
            this.Ans2BTN.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.Ans2BTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Ans2BTN.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Bold);
            this.Ans2BTN.ForeColor = System.Drawing.Color.Transparent;
            this.Ans2BTN.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.Ans2BTN.Location = new System.Drawing.Point(12, 148);
            this.Ans2BTN.Name = "Ans2BTN";
            this.Ans2BTN.Size = new System.Drawing.Size(744, 27);
            this.Ans2BTN.TabIndex = 82;
            this.Ans2BTN.Text = "Exit";
            this.Ans2BTN.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.Ans2BTN.UseVisualStyleBackColor = false;
            this.Ans2BTN.Click += new System.EventHandler(this.Ans2BTN_Click);
            // 
            // Ans1BTN
            // 
            this.Ans1BTN.BackColor = System.Drawing.Color.DarkGray;
            this.Ans1BTN.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.Ans1BTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Ans1BTN.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Bold);
            this.Ans1BTN.ForeColor = System.Drawing.Color.Transparent;
            this.Ans1BTN.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.Ans1BTN.Location = new System.Drawing.Point(12, 115);
            this.Ans1BTN.Name = "Ans1BTN";
            this.Ans1BTN.Size = new System.Drawing.Size(744, 27);
            this.Ans1BTN.TabIndex = 83;
            this.Ans1BTN.Text = "Exit";
            this.Ans1BTN.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.Ans1BTN.UseVisualStyleBackColor = false;
            this.Ans1BTN.Click += new System.EventHandler(this.Ans1BTN_Click);
            // 
            // TimeLBL
            // 
            this.TimeLBL.AutoSize = true;
            this.TimeLBL.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Bold);
            this.TimeLBL.Location = new System.Drawing.Point(313, 270);
            this.TimeLBL.Name = "TimeLBL";
            this.TimeLBL.Size = new System.Drawing.Size(85, 21);
            this.TimeLBL.TabIndex = 84;
            this.TimeLBL.Text = "Time Left:";
            // 
            // timer
            // 
            this.timer.Enabled = true;
            this.timer.Interval = 1000;
            this.timer.Tick += new System.EventHandler(this.Timer_Tick);
            // 
            // QuestionLBL
            // 
            this.QuestionLBL.AutoSize = true;
            this.QuestionLBL.Font = new System.Drawing.Font("Segoe UI", 11F, System.Drawing.FontStyle.Bold);
            this.QuestionLBL.Location = new System.Drawing.Point(9, 78);
            this.QuestionLBL.Name = "QuestionLBL";
            this.QuestionLBL.Size = new System.Drawing.Size(485, 20);
            this.QuestionLBL.TabIndex = 85;
            this.QuestionLBL.Text = "Who wrote the 1967 horror novel Who wrote the 1967 horror novel";
            // 
            // TriviaWin
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Turquoise;
            this.ClientSize = new System.Drawing.Size(768, 361);
            this.Controls.Add(this.QuestionLBL);
            this.Controls.Add(this.TimeLBL);
            this.Controls.Add(this.Ans1BTN);
            this.Controls.Add(this.Ans2BTN);
            this.Controls.Add(this.Ans4BTN);
            this.Controls.Add(this.Ans3BTN);
            this.Controls.Add(this.BackToMenuBTN);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "TriviaWin";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Trivia";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button BackToMenuBTN;
        private System.Windows.Forms.Timer timer;
        public System.Windows.Forms.Label TimeLBL;
        private System.Windows.Forms.Button Ans3BTN;
        private System.Windows.Forms.Button Ans4BTN;
        private System.Windows.Forms.Button Ans2BTN;
        private System.Windows.Forms.Button Ans1BTN;
        private System.Windows.Forms.Label QuestionLBL;
    }
}