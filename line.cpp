#include <bits/stdc++.h>

using namespace std;


long long cross(pair<long long, long long> & base, pair<long long, long long> first, pair<long long, long long> second){
  first.first -= base.first;
  first.second -= base.second;
  second.first -= base.first;
  second.second -= base.second;
  return (long long)first.first * second.second - (long long)first.second * second.first;
}

long long dist(pair<long long, long long> & a, pair<long long, long long> b){
  return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

int main(){
  int cases;
  cin >> cases;
  for (int blub = 0; blub < cases; blub++){
    pair<long long, long long> p1, p2, p3, p4;
    cin >> p1.first >> p1.second >> p2.first >> p2.second  >> p3.first >> p3.second  >> p4.first >> p4.second ;
    
    long long cc1 = cross(p1, p2, p3);
    long long cc2 = cross(p1, p2, p4);
    long long cc3 = cross(p3, p4, p1);
    long long cc4 = cross(p3, p4, p2);
    long long c1 = cc1 * cc2;
    long long c2 = cc3 * cc4;
    long long l1 = dist(p1,p2);
    long long l2 = dist(p3,p4);
    if ((c1 < 0 && c2 < 0)){
      //Line segments cross and there are no three colinear points
      cout << "POINT\n";
    }else if (cc1 == 0 && cc2 == 0 && cc3 == 0 && cc4 == 0){
      //Line segments are both on the same line (all points are colinear)
      if (dist(p1, p3) <= l1 && dist(p2, p3) <= l1 && l1 * l2 > 0 && dist(p1, p4) <= l1 && dist(p2, p4) <= l1){
	//Line 2 is a part of Line 1 and the lines are not points
	cout << "SEGMENT\n";
      }else if (dist(p3, p1) <= l2 && dist(p4, p1) <= l2 && l1 * l2 > 0 && dist(p3, p2) <= l2 && dist(p4, p2) <= l2){
	//Line 1 is a part of Line 2 and the lines are not points
	cout << "SEGMENT\n";
      }else if (dist(p1, p3) < l1 && dist(p2, p3) < l1 && l1 * l2 > 0){
	//The first point of Line 2 lies inside Line 1 and the lines are not points
	cout << "SEGMENT\n";
      }else if (dist(p1, p3) <= l1 && dist(p2, p3) <= l1){
	//The first point of Line 2 lies on one of the ends of Line 1
	cout << "POINT\n";
      }else if (dist(p1, p4) < l1 && dist(p2, p4) < l1 && l1 * l2 > 0){
	//The second point of Line 2 lies inside Line 1 and the lines are not points
	cout << "SEGMENT\n";
      }else if (dist(p1, p4) <= l1 && dist(p2, p4) <= l1){
	//The second point of Line 2 lies on one of the ends of Line 1
	cout << "POINT\n";
      }else if (dist(p3, p1) <= l2 && dist(p4, p1) <= l2){
	//The first point of Line 1 lies on one of the ends of Line 2 (needed because Line 1 can be a point)
	cout << "POINT\n";
      }else{
	cout << "NO\n";
      }
    }else if (cc1 == 0 && dist(p1, p3) <= l1 && dist(p2, p3) <= l1){
      //The first point of Line 2 lies on Line 1
      cout << "POINT\n";
    }else if (cc2 == 0 && dist(p1, p4) <= l1 && dist(p2, p4) <= l1){
      //The second point of Line 2 lies on Line 1
      cout << "POINT\n";
    }else if (cc3 == 0 && dist(p3, p1) <= l2 && dist(p4, p1) <= l2){
      //The first point of Line 1 lies on Line 2
      cout << "POINT\n";
    }else if (cc4 == 0 && dist(p3, p2) <= l2 && dist(p4, p2) <= l2){
      //The second point of Line 1 lies on Line 2
      cout << "POINT\n";
    }else{
      cout << "NO\n";
    }
  }
}
