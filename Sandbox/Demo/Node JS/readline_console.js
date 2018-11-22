const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
})

var enterText;
readline.question(`Input the string : `, (enterText) => {
  console.log(`Entered text is : ${enterText}`)
  
  var wordCount = findNoOfWords(enterText);
  var letterCount = findNoOfLetters(enterText);
  
  console.log(`Number of words : ${wordCount}`); 
  console.log(`Number of letters : ${letterCount}`);
  
  readline.close()
})


function findNoOfWords(str)
{
	return str.split(" ").length;
}

function findNoOfLetters(str)
{
	var sum = 0;
	var wordsCount = findNoOfWords(str);
	var strArray = str.split(" ");
	for(var i=0;i<wordsCount;i++)
	{
		sum += strArray[i].length;
	}
	return sum;
}

