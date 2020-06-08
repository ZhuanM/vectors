 #pragma once
 #include "Line.h"
 #include <iostream>

 class Segment : public Line {

 public:
   Segment();
   //Segment(const Line&);
   Segment(const Point&, const Vector&);
   Segment(const Point&, const Vector&, double, double);
   ~Segment();
   Segment(const Segment&);
   Segment& operator=(const Segment&);

   double getT(int n)const;
   void setT(int, double);
   double length();
   Point midPoint(); 

   bool operator==(const Point&);
    
   //virtual void menu();

   virtual std::istream& extractor(std::istream& i);
   virtual std::ostream& inserter(std::ostream& o) const;

 private:
   double t[2];
 };