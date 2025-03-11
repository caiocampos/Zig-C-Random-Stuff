namespace WindowsFormsApplication1
{
    partial class Form1
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
            this.chkSRF = new System.Windows.Forms.CheckBox();
            this.chkSRS = new System.Windows.Forms.CheckBox();
            this.chkGE = new System.Windows.Forms.CheckBox();
            this.txtDataInicial = new System.Windows.Forms.TextBox();
            this.lblDF = new System.Windows.Forms.Label();
            this.lblDI = new System.Windows.Forms.Label();
            this.txtDataFinal = new System.Windows.Forms.TextBox();
            this.txtPerc = new System.Windows.Forms.TextBox();
            this.lblPerc = new System.Windows.Forms.Label();
            this.grpProduto = new System.Windows.Forms.GroupBox();
            this.btnSalvar = new System.Windows.Forms.Button();
            this.dgvProdutos = new System.Windows.Forms.DataGridView();
            this.dcolProduto = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dcolSRF = new System.Windows.Forms.DataGridViewCheckBoxColumn();
            this.dcolSRS = new System.Windows.Forms.DataGridViewCheckBoxColumn();
            this.dcolGE = new System.Windows.Forms.DataGridViewCheckBoxColumn();
            this.dcolExcluir = new System.Windows.Forms.DataGridViewButtonColumn();
            this.btnIncluir = new System.Windows.Forms.Button();
            this.lblNomeProduto = new System.Windows.Forms.Label();
            this.txtProduto = new System.Windows.Forms.TextBox();
            this.lblProduto = new System.Windows.Forms.Label();
            this.lblDesc = new System.Windows.Forms.Label();
            this.txtDesc = new System.Windows.Forms.TextBox();
            this.lblCategora = new System.Windows.Forms.Label();
            this.cboCategoria = new System.Windows.Forms.ComboBox();
            this.grpProduto.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvProdutos)).BeginInit();
            this.SuspendLayout();
            // 
            // chkSRF
            // 
            this.chkSRF.AutoSize = true;
            this.chkSRF.Location = new System.Drawing.Point(6, 43);
            this.chkSRF.Name = "chkSRF";
            this.chkSRF.Size = new System.Drawing.Size(171, 21);
            this.chkSRF.TabIndex = 1;
            this.chkSRF.Text = "Seguro Roubo e Furto";
            this.chkSRF.UseVisualStyleBackColor = true;
            // 
            // chkSRS
            // 
            this.chkSRS.AutoSize = true;
            this.chkSRS.Location = new System.Drawing.Point(183, 43);
            this.chkSRS.Name = "chkSRS";
            this.chkSRS.Size = new System.Drawing.Size(224, 21);
            this.chkSRS.TabIndex = 2;
            this.chkSRS.Text = "Seguro Roubo e Furto Simples";
            this.chkSRS.UseVisualStyleBackColor = true;
            // 
            // chkGE
            // 
            this.chkGE.AutoSize = true;
            this.chkGE.Location = new System.Drawing.Point(413, 43);
            this.chkGE.Name = "chkGE";
            this.chkGE.Size = new System.Drawing.Size(152, 21);
            this.chkGE.TabIndex = 3;
            this.chkGE.Text = "Garantia Estendida";
            this.chkGE.UseVisualStyleBackColor = true;
            // 
            // txtDataInicial
            // 
            this.txtDataInicial.Location = new System.Drawing.Point(291, 34);
            this.txtDataInicial.Name = "txtDataInicial";
            this.txtDataInicial.Size = new System.Drawing.Size(100, 22);
            this.txtDataInicial.TabIndex = 6;
            // 
            // lblDF
            // 
            this.lblDF.AutoSize = true;
            this.lblDF.Location = new System.Drawing.Point(397, 37);
            this.lblDF.Name = "lblDF";
            this.lblDF.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.lblDF.Size = new System.Drawing.Size(76, 17);
            this.lblDF.TabIndex = 7;
            this.lblDF.Text = "Data Final:";
            // 
            // lblDI
            // 
            this.lblDI.AutoSize = true;
            this.lblDI.Location = new System.Drawing.Point(204, 37);
            this.lblDI.Name = "lblDI";
            this.lblDI.Size = new System.Drawing.Size(81, 17);
            this.lblDI.TabIndex = 5;
            this.lblDI.Text = "Data Inicial:";
            // 
            // txtDataFinal
            // 
            this.txtDataFinal.Location = new System.Drawing.Point(479, 34);
            this.txtDataFinal.Name = "txtDataFinal";
            this.txtDataFinal.Size = new System.Drawing.Size(100, 22);
            this.txtDataFinal.TabIndex = 8;
            // 
            // txtPerc
            // 
            this.txtPerc.Location = new System.Drawing.Point(98, 34);
            this.txtPerc.Name = "txtPerc";
            this.txtPerc.Size = new System.Drawing.Size(100, 22);
            this.txtPerc.TabIndex = 4;
            // 
            // lblPerc
            // 
            this.lblPerc.AutoSize = true;
            this.lblPerc.Location = new System.Drawing.Point(12, 37);
            this.lblPerc.Name = "lblPerc";
            this.lblPerc.Size = new System.Drawing.Size(80, 17);
            this.lblPerc.TabIndex = 0;
            this.lblPerc.Text = "Percentual:";
            // 
            // grpProduto
            // 
            this.grpProduto.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.grpProduto.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.grpProduto.Controls.Add(this.btnSalvar);
            this.grpProduto.Controls.Add(this.dgvProdutos);
            this.grpProduto.Controls.Add(this.btnIncluir);
            this.grpProduto.Controls.Add(this.lblNomeProduto);
            this.grpProduto.Controls.Add(this.txtProduto);
            this.grpProduto.Controls.Add(this.lblProduto);
            this.grpProduto.Controls.Add(this.chkSRF);
            this.grpProduto.Controls.Add(this.chkSRS);
            this.grpProduto.Controls.Add(this.chkGE);
            this.grpProduto.Location = new System.Drawing.Point(12, 62);
            this.grpProduto.Name = "grpProduto";
            this.grpProduto.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.grpProduto.Size = new System.Drawing.Size(669, 251);
            this.grpProduto.TabIndex = 4;
            this.grpProduto.TabStop = false;
            // 
            // btnSalvar
            // 
            this.btnSalvar.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnSalvar.Location = new System.Drawing.Point(6, 221);
            this.btnSalvar.Name = "btnSalvar";
            this.btnSalvar.Size = new System.Drawing.Size(75, 23);
            this.btnSalvar.TabIndex = 9;
            this.btnSalvar.Text = "Salvar";
            this.btnSalvar.UseVisualStyleBackColor = true;
            // 
            // dgvProdutos
            // 
            this.dgvProdutos.AllowUserToAddRows = false;
            this.dgvProdutos.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dgvProdutos.BackgroundColor = System.Drawing.SystemColors.Control;
            this.dgvProdutos.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvProdutos.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dcolProduto,
            this.dcolSRF,
            this.dcolSRS,
            this.dcolGE,
            this.dcolExcluir});
            this.dgvProdutos.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
            this.dgvProdutos.GridColor = System.Drawing.SystemColors.Control;
            this.dgvProdutos.Location = new System.Drawing.Point(6, 99);
            this.dgvProdutos.Name = "dgvProdutos";
            this.dgvProdutos.RowTemplate.Height = 24;
            this.dgvProdutos.Size = new System.Drawing.Size(657, 116);
            this.dgvProdutos.TabIndex = 8;
            this.dgvProdutos.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
            // 
            // dcolProduto
            // 
            this.dcolProduto.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.dcolProduto.HeaderText = "Produto";
            this.dcolProduto.Name = "dcolProduto";
            // 
            // dcolSRF
            // 
            this.dcolSRF.HeaderText = "SRF";
            this.dcolSRF.Name = "dcolSRF";
            this.dcolSRF.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            this.dcolSRF.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
            // 
            // dcolSRS
            // 
            this.dcolSRS.HeaderText = "SRS";
            this.dcolSRS.Name = "dcolSRS";
            this.dcolSRS.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            this.dcolSRS.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
            // 
            // dcolGE
            // 
            this.dcolGE.HeaderText = "GE";
            this.dcolGE.Name = "dcolGE";
            this.dcolGE.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            this.dcolGE.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
            // 
            // dcolExcluir
            // 
            this.dcolExcluir.HeaderText = "Excluir";
            this.dcolExcluir.Name = "dcolExcluir";
            this.dcolExcluir.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            this.dcolExcluir.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
            this.dcolExcluir.Text = "Excluir";
            // 
            // btnIncluir
            // 
            this.btnIncluir.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnIncluir.Location = new System.Drawing.Point(588, 70);
            this.btnIncluir.Name = "btnIncluir";
            this.btnIncluir.Size = new System.Drawing.Size(75, 23);
            this.btnIncluir.TabIndex = 7;
            this.btnIncluir.Text = "Incluir";
            this.btnIncluir.UseVisualStyleBackColor = true;
            // 
            // lblNomeProduto
            // 
            this.lblNomeProduto.AutoSize = true;
            this.lblNomeProduto.Location = new System.Drawing.Point(180, 18);
            this.lblNomeProduto.Name = "lblNomeProduto";
            this.lblNomeProduto.Size = new System.Drawing.Size(109, 17);
            this.lblNomeProduto.TabIndex = 6;
            this.lblNomeProduto.Text = "lblNomeProduto";
            // 
            // txtProduto
            // 
            this.txtProduto.Location = new System.Drawing.Point(74, 15);
            this.txtProduto.Name = "txtProduto";
            this.txtProduto.Size = new System.Drawing.Size(100, 22);
            this.txtProduto.TabIndex = 5;
            // 
            // lblProduto
            // 
            this.lblProduto.AutoSize = true;
            this.lblProduto.Location = new System.Drawing.Point(6, 18);
            this.lblProduto.Name = "lblProduto";
            this.lblProduto.Size = new System.Drawing.Size(62, 17);
            this.lblProduto.TabIndex = 4;
            this.lblProduto.Text = "Produto:";
            // 
            // lblDesc
            // 
            this.lblDesc.AutoSize = true;
            this.lblDesc.Location = new System.Drawing.Point(12, 9);
            this.lblDesc.Name = "lblDesc";
            this.lblDesc.Size = new System.Drawing.Size(75, 17);
            this.lblDesc.TabIndex = 9;
            this.lblDesc.Text = "Descrição:";
            // 
            // txtDesc
            // 
            this.txtDesc.Location = new System.Drawing.Point(93, 6);
            this.txtDesc.Name = "txtDesc";
            this.txtDesc.Size = new System.Drawing.Size(100, 22);
            this.txtDesc.TabIndex = 10;
            // 
            // lblCategora
            // 
            this.lblCategora.AutoSize = true;
            this.lblCategora.Location = new System.Drawing.Point(199, 9);
            this.lblCategora.Name = "lblCategora";
            this.lblCategora.Size = new System.Drawing.Size(73, 17);
            this.lblCategora.TabIndex = 11;
            this.lblCategora.Text = "Categoria:";
            // 
            // cboCategoria
            // 
            this.cboCategoria.FormattingEnabled = true;
            this.cboCategoria.Location = new System.Drawing.Point(278, 6);
            this.cboCategoria.Name = "cboCategoria";
            this.cboCategoria.Size = new System.Drawing.Size(121, 24);
            this.cboCategoria.TabIndex = 12;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(693, 325);
            this.Controls.Add(this.cboCategoria);
            this.Controls.Add(this.lblCategora);
            this.Controls.Add(this.txtDesc);
            this.Controls.Add(this.lblDesc);
            this.Controls.Add(this.grpProduto);
            this.Controls.Add(this.lblPerc);
            this.Controls.Add(this.txtPerc);
            this.Controls.Add(this.txtDataInicial);
            this.Controls.Add(this.txtDataFinal);
            this.Controls.Add(this.lblDF);
            this.Controls.Add(this.lblDI);
            this.Name = "Form1";
            this.Text = "Form1";
            this.grpProduto.ResumeLayout(false);
            this.grpProduto.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvProdutos)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox chkSRF;
        private System.Windows.Forms.CheckBox chkSRS;
        private System.Windows.Forms.CheckBox chkGE;
        private System.Windows.Forms.TextBox txtDataInicial;
        private System.Windows.Forms.Label lblDF;
        private System.Windows.Forms.Label lblDI;
        private System.Windows.Forms.TextBox txtDataFinal;
        private System.Windows.Forms.TextBox txtPerc;
        private System.Windows.Forms.Label lblPerc;
        private System.Windows.Forms.GroupBox grpProduto;
        private System.Windows.Forms.Button btnIncluir;
        private System.Windows.Forms.Label lblNomeProduto;
        private System.Windows.Forms.TextBox txtProduto;
        private System.Windows.Forms.Label lblProduto;
        private System.Windows.Forms.DataGridView dgvProdutos;
        private System.Windows.Forms.Button btnSalvar;
        private System.Windows.Forms.DataGridViewTextBoxColumn dcolProduto;
        private System.Windows.Forms.DataGridViewCheckBoxColumn dcolSRF;
        private System.Windows.Forms.DataGridViewCheckBoxColumn dcolSRS;
        private System.Windows.Forms.DataGridViewCheckBoxColumn dcolGE;
        private System.Windows.Forms.DataGridViewButtonColumn dcolExcluir;
        private System.Windows.Forms.Label lblDesc;
        private System.Windows.Forms.TextBox txtDesc;
        private System.Windows.Forms.Label lblCategora;
        private System.Windows.Forms.ComboBox cboCategoria;
    }
}

