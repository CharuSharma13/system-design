[plantUml](http://www.plantuml.com/plantuml/uml/bLDBpjCm4Dxx5ADiI5eYmJQ2gXK5gJiakC3K6LABnAdiIOLut1qthgbZjI6_DudyFUnlnhErZ8Q7hXMik2NOztBeI3Dyh1Nt1ahuqAAri5VO6Eo4iD-LFgFx1Na5Tin67GUcW-pr5_MJu8qGh-3zm-M0psIiianQ4koEbWrALhr-Bb6QoNn3IHFfBm5khIrUAAzxMO5pKhefn1yXndl19zNIonHxP3oYNQnAJoZBtvluaY8Opf7cYXKrewNhroufKn3TD2628LsJoOiGuPxxA_r8o2MxhK3qyeYKnsZnF_T3XmqbzcVaqzG-PkKHFESVNScNDKaklEaSOqdndtDymC0BuUZMgmek9Batxv93LniV2Uiw1Bv9AaYfC-a35RAtcGktWMoLfNgeGFQQKMcxAAgV-MM10pl47gSZG2k_PnsE3LNnW_VGUcgIJzMluQ6o-5Sur_hq6GPeRFgI9nHDzZZEIInNqdjhApYXBV4H9nxkGDkweuQk_Gi0)

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
