namespace TriviaClientGUI
{
    partial class RoomsWin
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
            this.label4 = new System.Windows.Forms.Label();
            this.JoinRoomBTN = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.BackToMenuBTN = new System.Windows.Forms.Button();
            this.RoomsLV = new System.Windows.Forms.ListView();
            this.RoomName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.CreatedBy = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.UsersLV = new System.Windows.Forms.ListView();
            this.UserName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.ErrorProvider = new System.Windows.Forms.ErrorProvider(this.components);
            this.RefreshBTN = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.ErrorProvider)).BeginInit();
            this.SuspendLayout();
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(12, 29);
            this.label4.Name = "label4";
            this.label4.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.label4.Size = new System.Drawing.Size(78, 25);
            this.label4.TabIndex = 66;
            this.label4.Text = "Rooms:";
            this.label4.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // JoinRoomBTN
            // 
            this.JoinRoomBTN.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(174)))), ((int)(((byte)(219)))));
            this.JoinRoomBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.JoinRoomBTN.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Bold);
            this.JoinRoomBTN.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.JoinRoomBTN.Location = new System.Drawing.Point(329, 309);
            this.JoinRoomBTN.Name = "JoinRoomBTN";
            this.JoinRoomBTN.Size = new System.Drawing.Size(124, 40);
            this.JoinRoomBTN.TabIndex = 64;
            this.JoinRoomBTN.Text = "Join Room";
            this.JoinRoomBTN.UseVisualStyleBackColor = false;
            this.JoinRoomBTN.Click += new System.EventHandler(this.JoinRoomBTN_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(284, 29);
            this.label1.Name = "label1";
            this.label1.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.label1.Size = new System.Drawing.Size(146, 25);
            this.label1.TabIndex = 76;
            this.label1.Text = "Users In Room:";
            this.label1.TextAlign = System.Drawing.ContentAlignment.TopRight;
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
            // RoomsLV
            // 
            this.RoomsLV.Alignment = System.Windows.Forms.ListViewAlignment.Default;
            this.RoomsLV.BackColor = System.Drawing.Color.SeaShell;
            this.RoomsLV.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.RoomName,
            this.CreatedBy});
            this.RoomsLV.FullRowSelect = true;
            this.RoomsLV.HideSelection = false;
            this.RoomsLV.Location = new System.Drawing.Point(12, 57);
            this.RoomsLV.MultiSelect = false;
            this.RoomsLV.Name = "RoomsLV";
            this.RoomsLV.RightToLeftLayout = true;
            this.RoomsLV.Size = new System.Drawing.Size(271, 246);
            this.RoomsLV.TabIndex = 82;
            this.RoomsLV.UseCompatibleStateImageBehavior = false;
            this.RoomsLV.View = System.Windows.Forms.View.Details;
            this.RoomsLV.ColumnWidthChanging += new System.Windows.Forms.ColumnWidthChangingEventHandler(this.RoomsLV_ColumnWidthChanging);
            this.RoomsLV.SelectedIndexChanged += new System.EventHandler(this.RoomsLV_SelectedIndexChanged);
            // 
            // RoomName
            // 
            this.RoomName.Text = "Room Name";
            this.RoomName.Width = 142;
            // 
            // CreatedBy
            // 
            this.CreatedBy.Text = "Created By";
            this.CreatedBy.Width = 125;
            // 
            // UsersLV
            // 
            this.UsersLV.Alignment = System.Windows.Forms.ListViewAlignment.Default;
            this.UsersLV.BackColor = System.Drawing.Color.SeaShell;
            this.UsersLV.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.UserName});
            this.UsersLV.FullRowSelect = true;
            this.UsersLV.HideSelection = false;
            this.UsersLV.Location = new System.Drawing.Point(289, 57);
            this.UsersLV.MultiSelect = false;
            this.UsersLV.Name = "UsersLV";
            this.UsersLV.RightToLeftLayout = true;
            this.UsersLV.Size = new System.Drawing.Size(164, 246);
            this.UsersLV.TabIndex = 83;
            this.UsersLV.UseCompatibleStateImageBehavior = false;
            this.UsersLV.View = System.Windows.Forms.View.Details;
            this.UsersLV.ColumnWidthChanging += new System.Windows.Forms.ColumnWidthChangingEventHandler(this.UsersLV_ColumnWidthChanging);
            // 
            // UserName
            // 
            this.UserName.Text = "User Name";
            this.UserName.Width = 159;
            // 
            // ErrorProvider
            // 
            this.ErrorProvider.BlinkStyle = System.Windows.Forms.ErrorBlinkStyle.AlwaysBlink;
            this.ErrorProvider.ContainerControl = this;
            // 
            // RefreshBTN
            // 
            this.RefreshBTN.BackColor = System.Drawing.Color.LightSeaGreen;
            this.RefreshBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.RefreshBTN.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Bold);
            this.RefreshBTN.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.RefreshBTN.Location = new System.Drawing.Point(66, 309);
            this.RefreshBTN.Name = "RefreshBTN";
            this.RefreshBTN.Size = new System.Drawing.Size(106, 40);
            this.RefreshBTN.TabIndex = 84;
            this.RefreshBTN.Text = "Refresh";
            this.RefreshBTN.UseVisualStyleBackColor = true;
            this.RefreshBTN.Click += new System.EventHandler(this.RefreshBTN_Click);
            // 
            // RoomsWin
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Turquoise;
            this.ClientSize = new System.Drawing.Size(484, 361);
            this.Controls.Add(this.RefreshBTN);
            this.Controls.Add(this.UsersLV);
            this.Controls.Add(this.RoomsLV);
            this.Controls.Add(this.BackToMenuBTN);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.JoinRoomBTN);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Name = "RoomsWin";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Rooms";
            this.Load += new System.EventHandler(this.RoomsWin_Load);
            ((System.ComponentModel.ISupportInitialize)(this.ErrorProvider)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button JoinRoomBTN;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button BackToMenuBTN;
        private System.Windows.Forms.ListView RoomsLV;
        private System.Windows.Forms.ColumnHeader RoomName;
        private System.Windows.Forms.ColumnHeader CreatedBy;
        private System.Windows.Forms.ListView UsersLV;
        private System.Windows.Forms.ColumnHeader UserName;
        private System.Windows.Forms.ErrorProvider ErrorProvider;
        private System.Windows.Forms.Button RefreshBTN;
    }
}