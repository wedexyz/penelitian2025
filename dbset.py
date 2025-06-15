from tinydb import TinyDB   
from tinydb import Query   
#membuat database 
db = TinyDB("todo_db.json")
new_item = {"name": "Data", "value": 6}
#menambahkan
#db.insert(new_item)

#update
db.update({'value': 12}) 
#melihat
Todo = Query()
result = db.get(Todo.name == 'Data')
print(result.get('value'))

