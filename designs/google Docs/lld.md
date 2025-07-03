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


It is following all solid principle, but it seems like SRP is breaking for Document Editor (but its not the case) and Document

🟢 Why Document Editor is not an SRP violation
SRP violation happens when a class has multiple independent reasons to change, e.g.:
If DocumentEditor implemented its own storage logic (DB/file logic inside itself) but its not implementing.
If it implemented the rendering logic (formatting text, handling images itself) but its not implementing.
👉 Here, it doesn’t. It simply delegates.


Even though in this, it doesn’t strictly violate SRP, it can still be improved for better separation of concerns, especially as complexity grows.
Solution - Introducing a DocumentRenderer which separates concerns clearly, and makes rendering strategies pluggable.

[plantUml](https://www.plantuml.com/plantuml/uml/ZLFDRjim3BxhAGXVOdjpWLsDekYX7T3RCEm5E9jp1DXo8Ch5W6tlFhco58K9ZEGYX_n-I95wPeVMBTEe3l1c7DbVs14h7J_X6rdMxCZuxpyA_EyJCBvJoSvgCq0_TvNwfpB6ozmj4ndtEj9w99ObqvCjAsWXS5VQuS90JwT0GgTdmweRaHc-wf7kBICmNj3XJ-IxMOTKD6nLH-yVz5iqqe3piTH4KCrnKNo5LNkz1uUt2GUI5YTqHs4HWC9ZnUrvP9q5k_GtMT7MiAUzK-Tc-oW6M3zj1jZtqLv2eagiPQ2OuhBQKGubVl-edAmeCORJwFgBH2fYZSkkNtljPYaOWgbpJuCs9UijoXw20q6RRsPCsb1I7qbYHiAfJDghr-SBmUXJdI_Nxv1SdfZwcFtrqCKseyCgtkWOdj1HdrXbll3uz-51lgXhm8q7f9IONa1cYtyRaA_jMGEABmNKJGD5NO3ajT3Dng4sh9IONQBvCnl24NaFcVVNmi8KXVCjQvgdN3ACcjMpFvTf_0y0)

![image](https://github.com/user-attachments/assets/36032b8a-2fe5-42a5-a501-37931ca86d59)



## 🟢 Relationship now

### DocumentEditor
- **has a** `Document`
- **adds elements** (text, images) to the `Document`
- **does NOT render or save**

### DocumentRenderer
- **takes** a `Document` and **produces** a rendered `string` output

### Persistence
- **saves** a rendered `string` (the document content)



