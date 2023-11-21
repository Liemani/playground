class Parent():  
  def display(self): 
    print("Inside Parent") 
    
    
class Child(Parent):  
  def show(self): 
    print("Inside Child") 
    
class GrandChild(Child):  
  def show(self): 
#     print("Inside GrandChild")          
    Child.show(self)

if __name__ == '__main__' :
  grandChild = GrandChild()    
  grandChild.show() 
  grandChild.display() 
