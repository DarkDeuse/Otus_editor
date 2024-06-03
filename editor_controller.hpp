#pragma once

#include "editor_model.hpp"
#include "shape.hpp"
#include <fstream>

namespace Editore {

    class EditoreController {
    public:
        EditoreController() = delete;

        EditoreController(EditoreModel::TPtr model)
            : model(std::move(model)) {
        }

        void SaveToFile(const std::string& filename) {
            std::ofstream out(filename);
            model->ForEachShape([&](const IShape::TPtr& shape) {
                out << shape->Serialize() << std::endl;
            });
            out.close();
        }

        void LoadFromFile(const std::string& filename) {
            std::ifstream in(filename);
            in.close();
        }


        template <class T, class... Args>
        IShape::TPtr AddShape(Args&&... args) {
            IShape::TPtr out = std::make_shared<T>(std::forward<Args>(args)...);

            model->AddShape(out);

            return out;
        }

        void DeleteShape(IShape::TPtr& shape) {
            model->DeleteShape(shape);
        }

    private:
        EditoreModel::TPtr model;
    };
}
