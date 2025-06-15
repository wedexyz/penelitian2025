from tinydb import TinyDB   
from tinydb import Query   
#membuat database 
db = TinyDB("todo_db.json")
Todo = Query()
while True :
    result = db.get(Todo.name == 'Data')
    print(result.get('value'))