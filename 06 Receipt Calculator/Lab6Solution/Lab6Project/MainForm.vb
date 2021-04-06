Option Explicit On
Option Strict On
'
'Programmer:
'Assignment:
'
Public Class MainForm
  'Init Global Vars/Const
  Const TAX_RATE As Decimal = 0.0775D
  '
  Const TIP_RATE_1 As Decimal = 0.15D
  Const TIP_RATE_2 As Decimal = 0.18D
  Const TIP_RATE_3 As Decimal = 0.2D
  '
  Const DISCOUNT_LEVEL_1 As Decimal = 15D
  Const DISCOUNT_LEVEL_2 As Decimal = 20D
  Const DISCOUNT_LEVEL_3 As Decimal = 40D
  Const DISCOUNT_LEVEL_4 As Decimal = 65D
  '
  Const DISCOUNT_PCT1 As Decimal = 0.05D
  Const DISCOUNT_PCT2 As Decimal = 0.1D
  Const DISCOUNT_PCT3 As Decimal = 0.15D
  Const DISCOUNT_PCT4 As Decimal = 0.2D
  Private Sub MyCloseButton_Click(sender As Object, e As EventArgs) Handles myCloseButton.Click
    Me.Close()
  End Sub

    Sub Calculate()
        'Initialize Vars
        Dim foodCost As Decimal = 0.0D
        Dim drinkCost As Decimal = 0.0D
        Dim subTotal As Decimal = 0.0D
        Dim taxAmount As Decimal = 0.0D
        Dim tipAmount As Decimal = 0.0D
        Dim discountAmount As Decimal = 0.0D
        Dim totalAmount As Decimal = 0.0D

        'INPUT - Convert user input to numbers
        Decimal.TryParse(foodTextBox.Text, foodCost)
        Decimal.TryParse(drinksTextBox.Text, drinkCost)
        Decimal.TryParse(tipsTextBox.Text, tipAmount)

        'CALCS - Calculations
        subTotal = foodCost + drinkCost

        'DISCOUNT CALC
        If subTotal >= DISCOUNT_LEVEL_1 Then
            If subTotal <= DISCOUNT_LEVEL_2 Then
                discountAmount = subTotal * DISCOUNT_PCT1
            Else
                If subTotal < DISCOUNT_LEVEL_3 Then
                    discountAmount = subTotal * DISCOUNT_PCT2
                Else
                    If subTotal < DISCOUNT_LEVEL_4 Then
                        discountAmount = subTotal * DISCOUNT_PCT3
                    Else
                        discountAmount = subTotal * DISCOUNT_PCT4
                    End If
                End If
            End If
        End If

        taxAmount = subTotal * TAX_RATE
        totalAmount = subTotal + taxAmount + tipAmount - discountAmount

        'OUTPUT - Show the results
        subTotalLabel.Text = subTotal.ToString("F2")
        taxLabel.Text = taxAmount.ToString("C2")
        discountsLabel.Text = discountAmount.ToString("C2")
        totalLabel.Text = totalAmount.ToString("C2")
    End Sub

    'MAIN
    Private Sub CalculateButton_Click(sender As Object, e As EventArgs) Handles calculateButton.Click
        Calculate()

        'Display/Hide Panels
        costsPanel.Visible = False
        receiptPanel.Visible = True

    End Sub

  Private Sub MainForm_FormClosing(sender As Object, e As FormClosingEventArgs) Handles MyBase.FormClosing
    Dim answer As DialogResult

    answer = MessageBox.Show("Are you sure?", "CONFIRM", MessageBoxButtons.OKCancel, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2)

    If answer = DialogResult.Cancel Then
      e.Cancel = True
    End If
  End Sub

  Private Sub FoodTextBox_KeyPress(sender As Object, e As KeyPressEventArgs) Handles foodTextBox.KeyPress
    If Not ((e.KeyChar >= "0" And e.KeyChar <= "9") Or e.KeyChar = "." Or e.KeyChar = ControlChars.Back) Then
      e.Handled = True
    End If
  End Sub

  Private Sub suggestTipButton_Click(sender As Object, e As EventArgs) Handles suggestTipButton.Click
    Dim subTotal As Decimal = 0.0D
    Dim suggestedTip1 As Decimal = 0.0D
    Dim suggestedTip2 As Decimal = 0.0D
    Dim suggestedTip3 As Decimal = 0.0D
    '
    Decimal.TryParse(subTotalLabel.Text, subTotal)

    If subTotal = 0.0D Then
      MessageBox.Show("Please press the calculate button first.")
    Else
      suggestedTip1 = TIP_RATE_1 * subTotal
      suggestedTip2 = TIP_RATE_2 * subTotal
      suggestedTip3 = TIP_RATE_3 * subTotal
      '
      MessageBox.Show(ControlChars.NewLine & TIP_RATE_1.ToString("P0") & " : " & suggestedTip1.ToString("C2") & ControlChars.NewLine & TIP_RATE_2.ToString("P0") & " : " & suggestedTip2.ToString("C2") & ControlChars.NewLine & TIP_RATE_3.ToString("P0") & " : " & suggestedTip3.ToString("C2"), "Suggested Tip:", MessageBoxButtons.OK, MessageBoxIcon.Information)
      '
      tipsTextBox.Text = suggestedTip2.ToString("F2")
    End If
  End Sub

    Private Sub yesRadioButton_CheckedChanged(sender As Object, e As EventArgs) Handles yesRadioButton.CheckedChanged, noRadioButton.CheckedChanged

    End Sub

    Private Sub tip1RadioButton_CheckedChanged(sender As Object, e As EventArgs) Handles tip3RadioButton.CheckedChanged, tip2RadioButton.CheckedChanged, tip1RadioButton.CheckedChanged

    End Sub
End Class
