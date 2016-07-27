#include <iostream>

using namespace std;

// Test string to demonstrate parsing.
string testString = "<head>"
  "The head\n"
  "</head>\n"
  "<body>\n"
  "the body \n"
  "some more body\n"
  "<a href=\"someUrl\">hyperlink text</a>\n"
  "<b>some bold text</b>\n"
  "<a href=\"anotherUrl\">hyperlink text</a>\n"
  "<i>some italic text</i>\n"
  "<b>some bold <i>and italic</i> text <a href=\"www.withHyperlinks.com\">with a hyperlink in it</a></b>\n"
  "</body>\n"
  "footer text";

/**
 * Get the HTML input from the user.
 *
 * @param html Pointer to the html string.
 */
void readInput(string* html)
{
  string line;

  cout << "Please enter your HTML terminated by an empty line:" << endl;

  while (true) {
    getline(cin, line, '\n');

    if (line.length() == 0) {
      break;
    }

    *html += line + "\n";
  }
}

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

    // Add pre-anchor text.
    parsedHtml += html->substr(startText, (i - startText));

    // Add url in place of anchor.
    parsedHtml += "(" + html->substr(startUrl, (endUrl - startUrl)) + ")";

    startText = endAnchor;
  }

  parsedHtml += html->substr(startText, (html->length() - startText));

  *html = parsedHtml;
}

/**
 * Replace any simple formatting, single character tag with an appropriate
 *   replacement.
 *
 * @param html    Pointer to the html string.
 * @param type    The type of tag to replace.
 * @param replace The character to replace the tag with.
 */
void parseSimpleFormatTag(string* html, string type, string replace)
{
  int startText     = 0;
  string parsedHtml = "";

  string openTag  = "<" + type + ">";
  string closeTag = "</" + type + ">";

  for (
    int i = html->find(openTag, 0);
    i != string::npos;
    i = html->find(openTag, ++i)
  ) {
    int startFormat = i + 3;
    int endFormat   = html->find(closeTag, i);
    
    // Add pre-formatted text.
    parsedHtml += html->substr(startText, (i - startText));

    // Add formetted text.
    parsedHtml += replace + html->substr(startFormat, (endFormat - startFormat)) + replace;

    startText = endFormat + 4;
  }

  parsedHtml += html->substr(startText, (html->length() - startText));

  *html = parsedHtml;
}

/**
 * Replace bold tags with asterisks.
 *
 * @param html Pointer to the html string.
 */
void parseBold(string* html)
{
  parseSimpleFormatTag(html, "b", "*");
}

/**
 * Replace italic tags with underscores.
 *
 * @param html Pointer to the html string.
 */
void parseItalic(string* html)
{
  parseSimpleFormatTag(html, "i", "_");
}

/**
 * Print the parsed html to the screen.
 *
 * @param html Pointer to the html string.
 */
void printOutput(string* html)
{
  cout << endl << "Parsed HTML output:" << endl;
  cout << *html << endl;
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

  // html = &testString;
  readInput(html);

  parseBody(html);
  parseLinks(html);
  parseBold(html);
  parseItalic(html);

  printOutput(html);
}
