/* variables */
var inputSite = document.getElementById('input_site');
var inputUsername = document.getElementById('input_username');
var inputPassword = document.getElementById('input_password');
var inputCounter = document.getElementById('input_counter');

var deriveBtn = document.getElementById('derive');
var copyBtn = document.getElementById('copy');

var derivedPassword;

/* event listeners */
deriveBtn.addEventListener('click', onDerive);
copyBtn.addEventListener('click', onCopy);


/* derive a password from the input parameters and put in the clipboard */
async function onDerive() {
  var site = inputSite.value;
  var username = inputUsername.value;
  var password = inputPassword.value;
  var counter = inputCounter.value;

  derivedPassword = await sha256(site);
  console.log(derivedPassword);
}

/* copy the generated password to the clipboard */
function onCopy() {
  var textArea = document.createElement("textarea");

  // do not display the derived password on the screen
  textArea.style.position = 'fixed';
  textArea.style.top = 0;
  textArea.style.left = 0;

  textArea.style.width = '2em';
  textArea.style.height = '2em';

  textArea.style.padding = 0;

  textArea.style.border = 'none';
  textArea.style.outline = 'none';
  textArea.style.boxShadow = 'none';

  textArea.style.background = 'transparent';

  document.body.appendChild(textArea);

  textArea.focus();
  textArea.select();

  try {
    if ( false == document.execCommand('copy') ) {
      console.log("Unable to copy to clipboard");
    }
  } catch (err) {
    console.log("Unable to copy to clipboard");
  }

  document.body.removeChild(textArea);
}

/* sha256: TODO */
async function sha256(message) {
    // encode as UTF-8
    const msgBuffer = new TextEncoder('utf-8').encode(message);     

    const hashBuffer = await crypto.subtle.digest('SHA-256', msgBuffer)

    const hashArray = Array.from(new Uint8Array(hashBuffer));

    // convert bytes to hex string                  
    const hashHex = hashArray.map(b => ('00' + b.toString(16)).slice(-2)).join('');
    return hashHex;
}
