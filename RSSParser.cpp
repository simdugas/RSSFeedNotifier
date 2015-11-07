
#include <iostream>
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;

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


const char *
val( XMLElement *item, const char *attr )
{
    XMLElement *child = item->FirstChildElement( attr );
    return( child->GetText() );
}

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
