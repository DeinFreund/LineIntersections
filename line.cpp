#include <bits/stdc++.h>

using namespace std;


long long cross(pair<int, int> const& base, pair<int, int> first, pair<int, int> second){
  first.first -= base.first;
  first.second -= base.second;
  second.first -= base.first;
  second.second -= base.second;
  return (long long)first.first * second.second - (long long)first.second * second.first;
}

long long dist(pair<int, int> const& a, pair<int, int> const& b){
  return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

int main(){
  int cases;
  cin >> cases;
  for (int blub = 0; blub < cases; blub++){
    pair<int, int> p1, p2, p3, p4;
    cin >> p1.first >> p1.second >> p2.first >> p2.second  >> p3.first >> p3.second  >> p4.first >> p4.second;

    if (p1 > p2) swap(p1, p2);
    if (p3 > p4) swap(p3, p4);

    const long long cc1 = cross(p1, p2, p3);
    const long long cc2 = cross(p1, p2, p4);
    const long long cc3 = cross(p3, p4, p1);
    const long long cc4 = cross(p3, p4, p2);
    const long long c1 = cc1 * cc2;
    const long long c2 = cc3 * cc4;
    const long long l1 = dist(p1,p2);
    const long long l2 = dist(p3,p4);
    if (max(c1,c2) > 0){
      //Line segments are not crossing
      cout << "NO\n";
    }else if (min(c1,c2) < 0){
      //Line segments cross and there are no three colinear points
      cout << "POINT\n";
    }else if (cc1 == 0 && cc2 == 0){
      pair<pair<int,int>, pair<int,int>> points[2]{{p1,p2}, {p3,p4}};
      //sort lines
      sort(begin(points), end(points));
      //If second line starts before first line ends and is not a point, we have a segment intersection
      if (points[1].first < points[0].second && l1 * l2 > 0) cout << "SEGMENT\n";
      //If second line starts exactly where first line ends, we have a point intersection
      else if (points[1].first <= points[0].second) cout << "POINT\n";
      else cout << "NO\n";
    }else{
      //Three colinear points and one point on a line
      cout << "POINT\n";
    }
  }
}
