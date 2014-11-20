#ifndef MEDIA_H
#define MEDIA_H
class Media : public Transaction 
{
public:
  // A pure virtual display function
  void display();
  // A pure virtual sort function
  void sort();
  string title;
  // Movie or music or whatevr type of media this is.
  int type;
};
#endif
