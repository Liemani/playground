function logNamesAndMajors() {
  const SPREADSHEET_ID = '1cAUeb5wvve8yz6ZGj0L1KXpD1ham8OV6_m-By5AsL4s';

  const HOT_BEVERAGE_COLUMN = 1;
  const ICE_BEVERAGE_COLUMN = 7;

  const INPUT_SHEET_NAME = "음료 순이익";
  const OUTPUT_SHEET_NAME = "메뉴 목록";

  const spreadsheet = SpreadsheetApp.openById(SPREADSHEET_ID);
  const inputSheet = spreadsheet.getSheetByName(INPUT_SHEET_NAME);
  const outputSheet = spreadsheet.getSheetByName(OUTPUT_SHEET_NAME);

  let inputRow = 1;
  let outputRow = 2;

  let value = null;
  let productName = null;

  while (true) {
    const startInputRow = inputRow;

    value = getValue(inputSheet, inputRow, HOT_BEVERAGE_COLUMN);

    if (value == "") {
      value = getValue(inputSheet, inputRow, ICE_BEVERAGE_COLUMN);
      if (value == "")
        break;
    }

    while (true) {
      value = getValue(inputSheet, inputRow, HOT_BEVERAGE_COLUMN);
      if (value == "합계") {
        value = getValue(inputSheet, inputRow, ICE_BEVERAGE_COLUMN);
        if (value == "합계")
          break;
      }

      ++inputRow;
    }

    productName = getValue(inputSheet, startInputRow, HOT_BEVERAGE_COLUMN);
    if (productName != "") {
      Logger.log(productName);
      const purchaseCost = getValue(inputSheet, inputRow, HOT_BEVERAGE_COLUMN + 2);
      const sellingPrice = getValue(inputSheet, inputRow, HOT_BEVERAGE_COLUMN + 3);
      const profit = getValue(inputSheet, inputRow, HOT_BEVERAGE_COLUMN + 4);

      setOutputSheet(outputSheet, outputRow, productName, purchaseCost, sellingPrice, profit);

      ++outputRow;
    }

    productName = getValue(inputSheet, startInputRow, ICE_BEVERAGE_COLUMN);
    if (productName != "") {
      Logger.log(productName);
      const purchaseCost = getValue(inputSheet, inputRow, ICE_BEVERAGE_COLUMN + 2);
      const sellingPrice = getValue(inputSheet, inputRow, ICE_BEVERAGE_COLUMN + 3);
      const profit = getValue(inputSheet, inputRow, ICE_BEVERAGE_COLUMN + 4);

      setOutputSheet(outputSheet, outputRow, productName, purchaseCost, sellingPrice, profit);

      ++outputRow;
    }
    
    ++inputRow;
    ++inputRow;
  }
}

function setOutputSheet(sheet, row, productName, purchaseCost, sellingPrice, profit) {
  setValue(sheet, row, 1, productName);
  setValue(sheet, row, 2, purchaseCost);
  setValue(sheet, row, 3, sellingPrice);
  setValue(sheet, row, 4, profit);

}

function getValue(sheet, row, column) {
  return sheet.getRange(row, column).getValue();
}

function setValue(sheet, row, column, value) {
  sheet.getRange(row, column).setValue(value);
}
