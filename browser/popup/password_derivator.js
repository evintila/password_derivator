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


/* handle request to derive a password from the input parameters */
async function onDerive() {
  const site = inputSite.value;
  const username = inputUsername.value;
  const password = inputPassword.value;
  const counter = inputCounter.value;

  derivedPassword = await derivePassword(site, username, password, counter);
}


/* derive the password */
async function derivePassword(site, username, password, counter) {
  // concatenate padded parameters and hash
  
  const feed = pad(site) + pad(username) + pad(password) + pad(counter);
  
  var hashedValue = await hash(feed);
  return hashedValue;
}

/* pad the feed with its length to avoid concatenation collisions 
  ("ab" + "b" == "a" + "bc")
*/
function pad(feed) {
  return feed + feed.length;
}


/* put the derived password in the clipboard */
function onCopy() {
  // use a textArea to copy to clipboard
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

  // set the value to be copied
  textArea.value = derivedPassword;

  document.body.appendChild(textArea);


  // select and copy
  textArea.focus();
  textArea.select();
  try {
    if ( false == document.execCommand('copy') ) {
      console.log("Unable to copy to clipboard");
    }
  } catch (err) {
    console.log("Unable to copy to clipboard");
  }

  // remove the no longer needed textArea
  document.body.removeChild(textArea);
}


/* hash and base64 encode */
async function hash(feed) {
    // utf8 encode the feed
    const utf8Feed = new TextEncoder('utf-8').encode(feed);

    // hash the feed using SHA-256
    const hashedFeed = await crypto.subtle.digest('SHA-256', utf8Feed);


    // convert the hashed feed to a string binary representation
    const hashedFeedArray = new Uint8Array(hashedFeed);

    var binaryString = "";
    for (var i = 0; i < hashedFeedArray.byteLength; i++) {
        binaryString += String.fromCharCode(hashedFeedArray[i]);
    }


    // convert to base64 and trim
    const base64String = btoa(binaryString);
    // the hash result has 32 bytes and the base64 encoding pads it to 33    
    const trimmedBase64String = base64String.substring(0, base64String.length - 1);
    
    return trimmedBase64String;
}
