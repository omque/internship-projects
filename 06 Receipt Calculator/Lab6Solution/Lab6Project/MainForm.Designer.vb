<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class MainForm
  Inherits System.Windows.Forms.Form

  'Form overrides dispose to clean up the component list.
  <System.Diagnostics.DebuggerNonUserCode()> _
  Protected Overrides Sub Dispose(ByVal disposing As Boolean)
    Try
      If disposing AndAlso components IsNot Nothing Then
        components.Dispose()
      End If
    Finally
      MyBase.Dispose(disposing)
    End Try
  End Sub

  'Required by the Windows Form Designer
  Private components As System.ComponentModel.IContainer

  'NOTE: The following procedure is required by the Windows Form Designer
  'It can be modified using the Windows Form Designer.  
  'Do not modify it using the code editor.
  <System.Diagnostics.DebuggerStepThrough()> _
  Private Sub InitializeComponent()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.Label6 = New System.Windows.Forms.Label()
        Me.Label7 = New System.Windows.Forms.Label()
        Me.foodTextBox = New System.Windows.Forms.TextBox()
        Me.drinksTextBox = New System.Windows.Forms.TextBox()
        Me.subTotalLabel = New System.Windows.Forms.Label()
        Me.taxLabel = New System.Windows.Forms.Label()
        Me.totalLabel = New System.Windows.Forms.Label()
        Me.calculateButton = New System.Windows.Forms.Button()
        Me.myCloseButton = New System.Windows.Forms.Button()
        Me.suggestTipButton = New System.Windows.Forms.Button()
        Me.tipsTextBox = New System.Windows.Forms.TextBox()
        Me.discountsLabel = New System.Windows.Forms.Label()
        Me.costsPanel = New System.Windows.Forms.Panel()
        Me.GroupBox3 = New System.Windows.Forms.GroupBox()
        Me.couponCodeTextBox = New System.Windows.Forms.TextBox()
        Me.couponCodeLabel = New System.Windows.Forms.Label()
        Me.noRadioButton = New System.Windows.Forms.RadioButton()
        Me.yesRadioButton = New System.Windows.Forms.RadioButton()
        Me.taxRateGroupBox = New System.Windows.Forms.GroupBox()
        Me.county4RadioButton = New System.Windows.Forms.RadioButton()
        Me.county3RadioButton = New System.Windows.Forms.RadioButton()
        Me.county2RadioButton = New System.Windows.Forms.RadioButton()
        Me.county1RadioButton = New System.Windows.Forms.RadioButton()
        Me.serviceGroupBox = New System.Windows.Forms.GroupBox()
        Me.receiptPanel = New System.Windows.Forms.Panel()
        Me.tipGroupBox = New System.Windows.Forms.GroupBox()
        Me.tip3RadioButton = New System.Windows.Forms.RadioButton()
        Me.tip2RadioButton = New System.Windows.Forms.RadioButton()
        Me.tip1RadioButton = New System.Windows.Forms.RadioButton()
        Me.receiptGroupBox = New System.Windows.Forms.GroupBox()
        Me.costsPanel.SuspendLayout()
        Me.GroupBox3.SuspendLayout()
        Me.taxRateGroupBox.SuspendLayout()
        Me.serviceGroupBox.SuspendLayout()
        Me.receiptPanel.SuspendLayout()
        Me.tipGroupBox.SuspendLayout()
        Me.receiptGroupBox.SuspendLayout()
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.Location = New System.Drawing.Point(31, 34)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(60, 13)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "&Food:"
        Me.Label1.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'Label2
        '
        Me.Label2.Location = New System.Drawing.Point(31, 65)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(60, 13)
        Me.Label2.TabIndex = 2
        Me.Label2.Text = "&Drinks:"
        Me.Label2.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'Label3
        '
        Me.Label3.Location = New System.Drawing.Point(33, 23)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(60, 13)
        Me.Label3.TabIndex = 4
        Me.Label3.Text = "Subtotal:"
        Me.Label3.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'Label4
        '
        Me.Label4.Location = New System.Drawing.Point(33, 54)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(60, 13)
        Me.Label4.TabIndex = 6
        Me.Label4.Text = "Tax:"
        Me.Label4.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'Label5
        '
        Me.Label5.Location = New System.Drawing.Point(33, 85)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(60, 13)
        Me.Label5.TabIndex = 8
        Me.Label5.Text = "&Tip:"
        Me.Label5.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'Label6
        '
        Me.Label6.Location = New System.Drawing.Point(33, 116)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(60, 13)
        Me.Label6.TabIndex = 10
        Me.Label6.Text = "Di&scounts:"
        Me.Label6.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'Label7
        '
        Me.Label7.Location = New System.Drawing.Point(33, 147)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(60, 13)
        Me.Label7.TabIndex = 12
        Me.Label7.Text = "Total:"
        Me.Label7.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'foodTextBox
        '
        Me.foodTextBox.Location = New System.Drawing.Point(98, 31)
        Me.foodTextBox.Name = "foodTextBox"
        Me.foodTextBox.Size = New System.Drawing.Size(60, 20)
        Me.foodTextBox.TabIndex = 1
        Me.foodTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'drinksTextBox
        '
        Me.drinksTextBox.Location = New System.Drawing.Point(98, 62)
        Me.drinksTextBox.Name = "drinksTextBox"
        Me.drinksTextBox.Size = New System.Drawing.Size(60, 20)
        Me.drinksTextBox.TabIndex = 3
        Me.drinksTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'subTotalLabel
        '
        Me.subTotalLabel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.subTotalLabel.Location = New System.Drawing.Point(100, 23)
        Me.subTotalLabel.Name = "subTotalLabel"
        Me.subTotalLabel.Size = New System.Drawing.Size(60, 15)
        Me.subTotalLabel.TabIndex = 5
        Me.subTotalLabel.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'taxLabel
        '
        Me.taxLabel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.taxLabel.Location = New System.Drawing.Point(100, 54)
        Me.taxLabel.Name = "taxLabel"
        Me.taxLabel.Size = New System.Drawing.Size(60, 15)
        Me.taxLabel.TabIndex = 7
        Me.taxLabel.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'totalLabel
        '
        Me.totalLabel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.totalLabel.Location = New System.Drawing.Point(100, 147)
        Me.totalLabel.Name = "totalLabel"
        Me.totalLabel.Size = New System.Drawing.Size(60, 15)
        Me.totalLabel.TabIndex = 13
        Me.totalLabel.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'calculateButton
        '
        Me.calculateButton.Location = New System.Drawing.Point(78, 458)
        Me.calculateButton.Name = "calculateButton"
        Me.calculateButton.Size = New System.Drawing.Size(75, 23)
        Me.calculateButton.TabIndex = 14
        Me.calculateButton.Text = "&Calculate"
        Me.calculateButton.UseVisualStyleBackColor = True
        '
        'myCloseButton
        '
        Me.myCloseButton.Location = New System.Drawing.Point(135, 507)
        Me.myCloseButton.Name = "myCloseButton"
        Me.myCloseButton.Size = New System.Drawing.Size(75, 23)
        Me.myCloseButton.TabIndex = 15
        Me.myCloseButton.Text = "C&lose"
        Me.myCloseButton.UseVisualStyleBackColor = True
        '
        'suggestTipButton
        '
        Me.suggestTipButton.Location = New System.Drawing.Point(78, 458)
        Me.suggestTipButton.Name = "suggestTipButton"
        Me.suggestTipButton.Size = New System.Drawing.Size(75, 23)
        Me.suggestTipButton.TabIndex = 16
        Me.suggestTipButton.Text = "Suggest Tip"
        Me.suggestTipButton.UseVisualStyleBackColor = True
        '
        'tipsTextBox
        '
        Me.tipsTextBox.Location = New System.Drawing.Point(100, 82)
        Me.tipsTextBox.Name = "tipsTextBox"
        Me.tipsTextBox.Size = New System.Drawing.Size(60, 20)
        Me.tipsTextBox.TabIndex = 17
        Me.tipsTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'discountsLabel
        '
        Me.discountsLabel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.discountsLabel.Location = New System.Drawing.Point(100, 115)
        Me.discountsLabel.Name = "discountsLabel"
        Me.discountsLabel.Size = New System.Drawing.Size(60, 15)
        Me.discountsLabel.TabIndex = 18
        Me.discountsLabel.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'costsPanel
        '
        Me.costsPanel.Controls.Add(Me.GroupBox3)
        Me.costsPanel.Controls.Add(Me.taxRateGroupBox)
        Me.costsPanel.Controls.Add(Me.serviceGroupBox)
        Me.costsPanel.Controls.Add(Me.calculateButton)
        Me.costsPanel.Controls.Add(Me.myCloseButton)
        Me.costsPanel.Location = New System.Drawing.Point(12, 12)
        Me.costsPanel.Name = "costsPanel"
        Me.costsPanel.Size = New System.Drawing.Size(230, 551)
        Me.costsPanel.TabIndex = 19
        '
        'GroupBox3
        '
        Me.GroupBox3.Controls.Add(Me.couponCodeTextBox)
        Me.GroupBox3.Controls.Add(Me.couponCodeLabel)
        Me.GroupBox3.Controls.Add(Me.noRadioButton)
        Me.GroupBox3.Controls.Add(Me.yesRadioButton)
        Me.GroupBox3.Location = New System.Drawing.Point(20, 324)
        Me.GroupBox3.Name = "GroupBox3"
        Me.GroupBox3.Size = New System.Drawing.Size(190, 100)
        Me.GroupBox3.TabIndex = 2
        Me.GroupBox3.TabStop = False
        Me.GroupBox3.Text = "COUPON"
        '
        'couponCodeTextBox
        '
        Me.couponCodeTextBox.Location = New System.Drawing.Point(84, 59)
        Me.couponCodeTextBox.Name = "couponCodeTextBox"
        Me.couponCodeTextBox.Size = New System.Drawing.Size(87, 20)
        Me.couponCodeTextBox.TabIndex = 3
        Me.couponCodeTextBox.Visible = False
        '
        'couponCodeLabel
        '
        Me.couponCodeLabel.AutoSize = True
        Me.couponCodeLabel.Location = New System.Drawing.Point(9, 62)
        Me.couponCodeLabel.Name = "couponCodeLabel"
        Me.couponCodeLabel.Size = New System.Drawing.Size(75, 13)
        Me.couponCodeLabel.TabIndex = 2
        Me.couponCodeLabel.Text = "Coupon Code:"
        Me.couponCodeLabel.Visible = False
        '
        'noRadioButton
        '
        Me.noRadioButton.AutoSize = True
        Me.noRadioButton.Checked = True
        Me.noRadioButton.Location = New System.Drawing.Point(92, 31)
        Me.noRadioButton.Name = "noRadioButton"
        Me.noRadioButton.Size = New System.Drawing.Size(39, 17)
        Me.noRadioButton.TabIndex = 1
        Me.noRadioButton.TabStop = True
        Me.noRadioButton.Text = "No"
        Me.noRadioButton.UseVisualStyleBackColor = True
        '
        'yesRadioButton
        '
        Me.yesRadioButton.AutoSize = True
        Me.yesRadioButton.Location = New System.Drawing.Point(12, 31)
        Me.yesRadioButton.Name = "yesRadioButton"
        Me.yesRadioButton.Size = New System.Drawing.Size(43, 17)
        Me.yesRadioButton.TabIndex = 0
        Me.yesRadioButton.Text = "Yes"
        Me.yesRadioButton.UseVisualStyleBackColor = True
        '
        'taxRateGroupBox
        '
        Me.taxRateGroupBox.Controls.Add(Me.county4RadioButton)
        Me.taxRateGroupBox.Controls.Add(Me.county3RadioButton)
        Me.taxRateGroupBox.Controls.Add(Me.county2RadioButton)
        Me.taxRateGroupBox.Controls.Add(Me.county1RadioButton)
        Me.taxRateGroupBox.Location = New System.Drawing.Point(20, 161)
        Me.taxRateGroupBox.Name = "taxRateGroupBox"
        Me.taxRateGroupBox.Size = New System.Drawing.Size(190, 129)
        Me.taxRateGroupBox.TabIndex = 1
        Me.taxRateGroupBox.TabStop = False
        Me.taxRateGroupBox.Text = "TAX RATE"
        '
        'county4RadioButton
        '
        Me.county4RadioButton.Location = New System.Drawing.Point(12, 94)
        Me.county4RadioButton.Name = "county4RadioButton"
        Me.county4RadioButton.Size = New System.Drawing.Size(93, 17)
        Me.county4RadioButton.TabIndex = 3
        Me.county4RadioButton.Text = "San Francisco"
        Me.county4RadioButton.UseVisualStyleBackColor = True
        '
        'county3RadioButton
        '
        Me.county3RadioButton.Checked = True
        Me.county3RadioButton.Location = New System.Drawing.Point(12, 71)
        Me.county3RadioButton.Name = "county3RadioButton"
        Me.county3RadioButton.Size = New System.Drawing.Size(82, 17)
        Me.county3RadioButton.TabIndex = 2
        Me.county3RadioButton.TabStop = True
        Me.county3RadioButton.Text = "Sacramento"
        Me.county3RadioButton.UseVisualStyleBackColor = True
        '
        'county2RadioButton
        '
        Me.county2RadioButton.Location = New System.Drawing.Point(12, 48)
        Me.county2RadioButton.Name = "county2RadioButton"
        Me.county2RadioButton.Size = New System.Drawing.Size(83, 17)
        Me.county2RadioButton.TabIndex = 1
        Me.county2RadioButton.Text = "Los Angeles"
        Me.county2RadioButton.UseVisualStyleBackColor = True
        '
        'county1RadioButton
        '
        Me.county1RadioButton.Location = New System.Drawing.Point(12, 25)
        Me.county1RadioButton.Name = "county1RadioButton"
        Me.county1RadioButton.Size = New System.Drawing.Size(57, 17)
        Me.county1RadioButton.TabIndex = 0
        Me.county1RadioButton.Text = "Fresno"
        Me.county1RadioButton.UseVisualStyleBackColor = True
        '
        'serviceGroupBox
        '
        Me.serviceGroupBox.Controls.Add(Me.Label1)
        Me.serviceGroupBox.Controls.Add(Me.Label2)
        Me.serviceGroupBox.Controls.Add(Me.foodTextBox)
        Me.serviceGroupBox.Controls.Add(Me.drinksTextBox)
        Me.serviceGroupBox.Location = New System.Drawing.Point(20, 36)
        Me.serviceGroupBox.Name = "serviceGroupBox"
        Me.serviceGroupBox.Size = New System.Drawing.Size(190, 100)
        Me.serviceGroupBox.TabIndex = 0
        Me.serviceGroupBox.TabStop = False
        Me.serviceGroupBox.Text = "SERVICE"
        '
        'receiptPanel
        '
        Me.receiptPanel.Controls.Add(Me.tipGroupBox)
        Me.receiptPanel.Controls.Add(Me.receiptGroupBox)
        Me.receiptPanel.Controls.Add(Me.suggestTipButton)
        Me.receiptPanel.Location = New System.Drawing.Point(268, 12)
        Me.receiptPanel.Name = "receiptPanel"
        Me.receiptPanel.Size = New System.Drawing.Size(230, 551)
        Me.receiptPanel.TabIndex = 20
        Me.receiptPanel.Visible = False
        '
        'tipGroupBox
        '
        Me.tipGroupBox.Controls.Add(Me.tip3RadioButton)
        Me.tipGroupBox.Controls.Add(Me.tip2RadioButton)
        Me.tipGroupBox.Controls.Add(Me.tip1RadioButton)
        Me.tipGroupBox.Location = New System.Drawing.Point(17, 303)
        Me.tipGroupBox.Name = "tipGroupBox"
        Me.tipGroupBox.Size = New System.Drawing.Size(190, 100)
        Me.tipGroupBox.TabIndex = 1
        Me.tipGroupBox.TabStop = False
        Me.tipGroupBox.Text = "TIP"
        '
        'tip3RadioButton
        '
        Me.tip3RadioButton.AutoSize = True
        Me.tip3RadioButton.Location = New System.Drawing.Point(17, 73)
        Me.tip3RadioButton.Name = "tip3RadioButton"
        Me.tip3RadioButton.Size = New System.Drawing.Size(45, 17)
        Me.tip3RadioButton.TabIndex = 2
        Me.tip3RadioButton.Text = "20%"
        Me.tip3RadioButton.UseVisualStyleBackColor = True
        '
        'tip2RadioButton
        '
        Me.tip2RadioButton.AutoSize = True
        Me.tip2RadioButton.Location = New System.Drawing.Point(17, 48)
        Me.tip2RadioButton.Name = "tip2RadioButton"
        Me.tip2RadioButton.Size = New System.Drawing.Size(45, 17)
        Me.tip2RadioButton.TabIndex = 1
        Me.tip2RadioButton.Text = "18%"
        Me.tip2RadioButton.UseVisualStyleBackColor = True
        '
        'tip1RadioButton
        '
        Me.tip1RadioButton.AutoSize = True
        Me.tip1RadioButton.Checked = True
        Me.tip1RadioButton.Location = New System.Drawing.Point(17, 23)
        Me.tip1RadioButton.Name = "tip1RadioButton"
        Me.tip1RadioButton.Size = New System.Drawing.Size(45, 17)
        Me.tip1RadioButton.TabIndex = 0
        Me.tip1RadioButton.TabStop = True
        Me.tip1RadioButton.Text = "15%"
        Me.tip1RadioButton.UseVisualStyleBackColor = True
        '
        'receiptGroupBox
        '
        Me.receiptGroupBox.Controls.Add(Me.Label3)
        Me.receiptGroupBox.Controls.Add(Me.Label4)
        Me.receiptGroupBox.Controls.Add(Me.Label5)
        Me.receiptGroupBox.Controls.Add(Me.discountsLabel)
        Me.receiptGroupBox.Controls.Add(Me.Label6)
        Me.receiptGroupBox.Controls.Add(Me.tipsTextBox)
        Me.receiptGroupBox.Controls.Add(Me.Label7)
        Me.receiptGroupBox.Controls.Add(Me.subTotalLabel)
        Me.receiptGroupBox.Controls.Add(Me.taxLabel)
        Me.receiptGroupBox.Controls.Add(Me.totalLabel)
        Me.receiptGroupBox.Location = New System.Drawing.Point(17, 39)
        Me.receiptGroupBox.Name = "receiptGroupBox"
        Me.receiptGroupBox.Size = New System.Drawing.Size(190, 175)
        Me.receiptGroupBox.TabIndex = 0
        Me.receiptGroupBox.TabStop = False
        Me.receiptGroupBox.Text = "RECEIPT"
        '
        'MainForm
        '
        Me.AcceptButton = Me.calculateButton
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(517, 580)
        Me.Controls.Add(Me.receiptPanel)
        Me.Controls.Add(Me.costsPanel)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle
        Me.MaximizeBox = False
        Me.MinimizeBox = False
        Me.Name = "MainForm"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = " "
        Me.costsPanel.ResumeLayout(False)
        Me.GroupBox3.ResumeLayout(False)
        Me.GroupBox3.PerformLayout()
        Me.taxRateGroupBox.ResumeLayout(False)
        Me.serviceGroupBox.ResumeLayout(False)
        Me.serviceGroupBox.PerformLayout()
        Me.receiptPanel.ResumeLayout(False)
        Me.tipGroupBox.ResumeLayout(False)
        Me.tipGroupBox.PerformLayout()
        Me.receiptGroupBox.ResumeLayout(False)
        Me.receiptGroupBox.PerformLayout()
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents Label1 As Label
  Friend WithEvents Label2 As Label
  Friend WithEvents Label3 As Label
  Friend WithEvents Label4 As Label
  Friend WithEvents Label5 As Label
  Friend WithEvents Label6 As Label
  Friend WithEvents Label7 As Label
  Friend WithEvents foodTextBox As TextBox
  Friend WithEvents drinksTextBox As TextBox
    Friend WithEvents subTotalLabel As Label
    Friend WithEvents taxLabel As Label
    Friend WithEvents totalLabel As Label
    Friend WithEvents calculateButton As Button
    Friend WithEvents myCloseButton As Button
    Friend WithEvents suggestTipButton As Button
    Friend WithEvents tipsTextBox As TextBox
    Friend WithEvents discountsLabel As Label
    Friend WithEvents costsPanel As Panel
    Friend WithEvents receiptPanel As Panel
    Friend WithEvents GroupBox3 As GroupBox
    Friend WithEvents taxRateGroupBox As GroupBox
    Friend WithEvents serviceGroupBox As GroupBox
    Friend WithEvents county4RadioButton As RadioButton
    Friend WithEvents county3RadioButton As RadioButton
    Friend WithEvents county2RadioButton As RadioButton
    Friend WithEvents county1RadioButton As RadioButton
    Friend WithEvents noRadioButton As RadioButton
    Friend WithEvents yesRadioButton As RadioButton
    Friend WithEvents couponCodeTextBox As TextBox
    Friend WithEvents couponCodeLabel As Label
    Friend WithEvents tipGroupBox As GroupBox
    Friend WithEvents tip3RadioButton As RadioButton
    Friend WithEvents tip2RadioButton As RadioButton
    Friend WithEvents tip1RadioButton As RadioButton
    Friend WithEvents receiptGroupBox As GroupBox
End Class
