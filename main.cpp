#include "editor_controller.hpp"
#include "editor_model.hpp"
#include "editor_view.hpp"
#include "shape.hpp"

#include <memory>

int main() {
    auto editorView = std::make_unique<Editore::TEditorView>();
    auto editorModel = std::make_unique<Editore::EditoreModel>(std::move(editorView));
    auto editorController = Editore::EditoreController(std::move(editorModel));

    auto line1 = editorController.AddShape<Editore::TLine>(2, -5);
    auto line2 = editorController.AddShape<Editore::TLine>(1, 5);
    auto square1 = editorController.AddShape<Editore::TSquare>(20, 5, 4);

    editorController.DeleteShape(line1);

    editorController.SaveToFile("/tmp/editor.dump");
}
