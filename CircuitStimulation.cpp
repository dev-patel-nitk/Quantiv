#include<iostream>
using namespace std;

struct Inp {
 int val;
};

class TrueVal : public Inp {
 static TrueVal* ptr;
 TrueVal() {
  val = 1;
 }
 public:
 static TrueVal* get() {
  if(!ptr) ptr = new TrueVal();
  return ptr;
 }
};
TrueVal* TrueVal::ptr = NULL;

class FalseVal : public Inp {
 static FalseVal* ptr;
 FalseVal() {
  val = 0;
 }
 public:
 static FalseVal* get() {
  if(ptr == NULL) {
   ptr = new FalseVal();
  }
  return ptr;
 }
};
FalseVal* FalseVal::ptr = NULL;

class Gate {
public:
 virtual int calc(int a, int b) = 0;
};

class AND : public Gate {
 int calc(int a, int b) {
  if(a == 1 && b == 1) return 1;
  else return 0;
 }
};

class OR : public Gate {
 int calc(int a, int b){
  if(a==1 || b==1) return 1;
  return 0;
 }
};

class XOR : public Gate {
 int calc(int a, int b) {
  if(a != b) return 1;
  return 0;
 }
};

class NOT : public Gate{
 int calc(int a, int b){
  if(a==0) return 1;
  return 0;
 }
};

class NAND : public Gate{
    int calc(int a,int b){
        if(a==1 && b==1) return 0;
        return 1;
    }
};
class NOR : public Gate{
    int calc(int a,int b){
        if(a==0 && b==0) return 1;
        else return 0;
    }
};
class XNOR:public Gate{
    int calc(int a,int b){
        if(a==b) return 1;
        return 0;
    }
};

class MyCircuit {
 vector<Gate*> gates;
 public:
 void add(Gate* g){
  gates.push_back(g);
 }
 
 int doWork(vector<Inp*> inputs) {
  if(inputs.size() == 0) return 0;
  
  int ans = inputs[0]->val;
  
  for(int i=0; i<gates.size(); i++){
   if(i+1 < inputs.size()){
    ans = gates[i]->calc(ans, inputs[i+1]->val);
   }
  }
  return ans;
 }
};

void solve() {
 Inp* T = TrueVal::get();
 Inp* F = FalseVal::get();
 MyCircuit c;
 c.add(new AND());
 c.add(new OR());
 c.add(new XOR());
 
 vector<Inp*> v;
 v.push_back(T);
 v.push_back(T);
 v.push_back(F);
 v.push_back(T);
 
 cout << c.doWork(v) << endl;
 
 MyCircuit c2;
 c2.add(new NOT());
 vector<Inp*> v2;
 v2.push_back(F);
 cout<< c2.doWork(v2) << endl;
}

int main(){
 solve();
}