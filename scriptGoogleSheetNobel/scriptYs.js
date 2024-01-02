const sheetName = 'Données de départ';


function createNobelStat() {

    let sheet = SpreadsheetApp.getActiveSpreadsheet();

    let newSheet = sheet.insertSheet('NobelStat');

    sheet = SpreadsheetApp.getActiveSpreadsheet().getSheetByName('NobelStat');

    let categories = getCategories();

    console.log(categories)

    let startRow = 1;
    let startColumn = 2;
    let numRows = 1;
    let numColumns = categories[0].length;

    let range = sheet.getRange(startRow, startColumn, numRows, numColumns);
    
    range.setValues(categories);


    range = sheet.getRange('A2:A4');

    let tab = [[1],[2],[3]];

    range.setValues(tab);


    range = sheet.getRange('B2:G4');

    let tabChem = [[getCatOcc('chemistry', 1),getCatOcc('literature',1),getCatOcc('medicine',1),getCatOcc('peace',1),getCatOcc('physics',1),getCatOcc('economics',1)],
                   [getCatOcc('chemistry', 2),getCatOcc('literature',2),getCatOcc('medicine',2),getCatOcc('peace',2),getCatOcc('physics',2),getCatOcc('economics',2)],
                   [getCatOcc('chemistry', 3),getCatOcc('literature',3),getCatOcc('medicine',3),getCatOcc('peace',3),getCatOcc('physics',3),getCatOcc('economics',3)]];

    range.setValues(tabChem);

    range = sheet.getRange('B2:G2');

    let tabSingle = range.getValues();

    range = sheet.getRange('B3:G3');

    let tabDouble = range.getValues();

    range = sheet.getRange('B4:G4');

    let tabTriple = range.getValues();


    let sumSingle = AddTab(tabSingle);
    let sumDouble = AddTab(tabDouble);
    let sumTriple = AddTab(tabTriple);

    let sumAll = sumSingle + sumDouble + sumTriple;

    range = sheet.getRange('H1:H5');

    let collumnH = [['Total'],[sumSingle],[sumDouble],[sumTriple],[sumAll]];

    range.setValues(collumnH);



}

function AddTab(tab){


  let sum = 0;
  tab[0].forEach(function(item){
    sum = sum + item;
  })

  return sum;
}


function getCatOcc(cat, nbOcc){

  let sheet = SpreadsheetApp.getActiveSpreadsheet().getSheetByName(sheetName);
  let lastRow = sheet.getLastRow();
  let range =  sheet.getRange('B2:C' + lastRow);

  let tab = range.getValues();

  let newTab = new Array();
  let cpt = 0;

  tab.forEach(function(item,index){
    if(item[0] == cat){
      newTab[cpt] = item;
      cpt++;
    }
  });

  let tabSimple = new Array();

  cpt = 0;

  for(let i = 0; i < newTab.length; i++){
    let cptOcc = 0;
    let current = newTab[i][1];
    for(let j = 0; j < newTab.length; j++){
      if(current == newTab[j][1]){
        cptOcc++;
      }
    }


    if(cptOcc == nbOcc){
      let existingIndex = tabSimple.findIndex(el => el[0] === newTab[i][0] && el[1] === newTab[i][1]);
      if(existingIndex){
              tabSimple[cpt] = newTab[i];
              cpt++;
      }
    }

  }

  console.log(tabSimple);

  return tabSimple.length;
}

function getCategories(){
    let sheet = SpreadsheetApp.getActiveSpreadsheet().getSheetByName(sheetName);
    let lastRow = sheet.getLastRow();
    let range =  sheet.getRange('B2:B' + lastRow);

    let tabCat = range.getValues().flat();


    let tabCatSort = new Array();

    let cpt = 0;


    for(let i = 0; i < tabCat.length; i++){
      if(!(tabCatSort.includes(tabCat[i]))){
        tabCatSort[cpt] = tabCat[i];
        cpt++;
      }
    }

    let finalTab = [tabCatSort];


    console.log(finalTab);

    return finalTab;
}