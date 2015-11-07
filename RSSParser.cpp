
#include <iostream>

#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;

/** An RSS Feed has the following structure:
    <rss>
      <channel>
        ...
        <item> ... </item>
        <item> ... </item>
        ...
      </feed>
    </rss>
*/

/** Representation of a channel item.
*/
class RSSFeedItem
{
private:
  const char *title;
  const char *link;
  const char *description;
  const char *pubDate;
  const char *guid;
  const char *date;

public:
  RSSFeedItem(
    const char *title,
    const char *link,
    const char *description,
    const char *pubDate,
    const char *guid,
    const char *date
  ):
    title( title ),
    link( link ),
    description( description ),
    pubDate( pubDate ),
    guid( guid ),
    date( date )
    {}

  void
  print()
  {
    cout << title << endl;
  }
};

/** Get the text of the tag name for an item.
*/
const char *
val( XMLElement *item, const char *tag )
{
    XMLElement *child = item->FirstChildElement( tag );
    return( child->GetText() );
}

/** Returns a new RSSFeedItem object for the XML
    representation of the item.
*/
RSSFeedItem *
parseItem( XMLElement *item )
{
  RSSFeedItem *fItem = new RSSFeedItem(
    val( item, "title" ),
    val( item, "link" ),
    val( item, "description" ),
    val( item, "pubDate" ),
    val( item, "guid" ),
    NULL
  );
  return( fItem );
}

/** A Sample program to parse the items.
*/
int
main()
{
  XMLDocument doc;
  doc.LoadFile( "test.xml" );

  XMLElement *root = doc.FirstChildElement( "rss" );
  XMLElement *channel = root->FirstChildElement( "channel" );
  XMLElement *item = channel->FirstChildElement( "item" );

  while( item )
  {
    RSSFeedItem *fItem = parseItem( item );
    fItem->print();
    item = item->NextSiblingElement();
  }
}

