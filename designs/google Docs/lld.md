![image](https://github.com/user-attachments/assets/d9fd943f-345c-4d0d-8a05-ee8b0025c106)

# Document Editor Relationships

## DocumentEditor
- **has a** `Document`
- **has a** `Persistence`
- **calls** `Document.addElement()` and `Document.render()`
- **calls** `Persistence.save()`

## Persistence `<<interface>>`
- `FilePersistence` **is a** `Persistence`
- `DatabasePersistence` **is a** `Persistence`

## Document
- **has many** `DocumentElement`

## DocumentElement `<<interface>>`
- `TextElement` **is a** `DocumentElement`
- `ImageElement` **is a** `DocumentElement`

## TextElement & ImageElement
- **implements** `render()`

## FilePersistence & DatabasePersistence
- **implement** `save()`
