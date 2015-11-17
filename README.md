
# RSS Feed Notifier

## Basic Workflow
1. User inputs the feeds they want to follow.
2. The application constantly polls the feed for new updates (feed items).
3. Updates are presented to the user and disappear once they are marked as "read".

## Required Features
1. Add and remove a feed
2. View feed items and mark as read

## Dependencies
- cmake
- tinyxml2
    - I installed this using brew install tinyxml2 on my Mac
    - See http://www.grinninglizard.com/tinyxml2/
      
## Build
```
mkdir build
cd build
cmake ..
make
```

## Run
```
./RSSParser ../test.xml
```
