#include <iostream>

using namespace std;


/**
 * Extract the html from inside the body tags.
 *
 * @param html Pointer to the html string.
 */
void parseBody(string* html)
{
  int bodyStart = html->find("<body>") + 6;
  int bodyEnd   = html->find("</body>");

  *html = html->substr(bodyStart, (bodyEnd - bodyStart));
}

/**
 * Replace anchor tags with bracketed urls.
 *
 * @param html Pointer to the html string.
 */
void parseLinks(string* html)
{
  int startText     = 0;
  string parsedHtml = "";

  for (
    int i = html->find("<a href=\"", 0);
    i != string::npos;
    i = html->find("<a href=\"", ++i)
  ) {
    int endAnchor = html->find("</a>", i) + 4;
    int startUrl  = html->find('"', i) + 1;
    int endUrl    = html->find('"', startUrl);

    int endText = i;

    // Add pre-anchor text.
    parsedHtml += html->substr(startText, (endText - startText));

    // Add url in place of anchor.
    parsedHtml += "(" + html->substr(startUrl, (endUrl - startUrl)) + ")";

    startText = endAnchor;
  }

  parsedHtml += html->substr(startText, (html->length() - startText));  

  cout << parsedHtml << endl;
}

/**
 * Replace bold tags with asterisks.
 *
 * @param html Pointer to the html string.
 */
void parseBold(string* html)
{
  string type     = "b";
  string openTag  = "<" + type + ">";
  string closeTag = "</" + type + ">";

  for (
    int i = html->find(openTag, 0);
    i != string::npos;
    i = html->find(openTag, ++i)
  ) {
    
  }
}

/**
 * Replace italic tags with underscores.
 *
 * @param html Pointer to the html string.
 */
void parseItalic(string* html)
{

}

/**
 * Get the HTML input from the user.
 *
 * @param html Pointer to the html string.
 */
void readInput(string* html)
{
  cout << "Please enter your HTML:" << endl;
  getline(cin, *html, '\n');
}

/**
 * Basic HTML parsing program.
 *
 * Remove <head>, display text of <body> converting:
 *   <a href="url">text</a> => (url)
 *   <b>text</b>            => *text*
 *   <i>text</i>            => _text_
 */
int main()
{
  string* html = new string;

  readInput(html);

  parseBody(html);
  parseLinks(html);
  parseBold(html);
  parseItalic(html);

  // cout << *html << endl;
}
