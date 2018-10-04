function checkPassword()
{
	//Password must be 8-15 characters long, must contain atleast one lowercase letter, one uppercase letter and 1 number.
	var pattern =  /^(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{8,15}$/;
	var inputPswd = document.getElementById('inputPassword').value;
	var pswdHelpBlck = document.getElementById('passwordHelpBlock');
	document.getElementById('incorrectPswd').style.display='none';
	if(!(inputPswd.match(pattern)))
	{
		document.getElementById('inputPassword').focus();
		document.getElementById('inputPassword').value='';
		pswdHelpBlck.style.display='block';
		document.getElementById('register').disabled = true;
	}
	else
	{
		pswdHelpBlck.style.display='none';
		document.getElementById('register').disabled = false;
	}
}


function checkConfirmPassword()
{
	var incorrectPswdText = document.getElementById('incorrectPswd');
	var inputPswd = document.getElementById('inputPassword').value;
	var confirmPswd = document.getElementById('confirmPassword').value;
	if(inputPswd != confirmPswd && inputPswd !='')
	{
		document.getElementById('inputPassword').focus();
		document.getElementById('inputPassword').value='';
		document.getElementById('confirmPassword').value='';
		incorrectPswdText.style.display='block';
		document.getElementById('register').disabled = true;
	}
	else
	{
		incorrectPswdText.style.display='none';
		document.getElementById('register').disabled = false;
	}
}