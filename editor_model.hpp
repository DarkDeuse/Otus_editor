#pragma once

#include <algorithm>
#include <unordered_set>

#include "shape.hpp"
#include "editor_view.hpp"

namespace Editore {

    class EditoreModel {
    public:
        using TPtr = std::unique_ptr<EditoreModel>;

        EditoreModel() = delete;

        explicit EditoreModel(TEditorView::TPtr view)
            : view(std::move(view))
            , shapes({}) {
        }

        void AddShape(IShape::TPtr& shape) {
            shapes.emplace(shape);
            view->Draw(shapes);
        };

        void DeleteShape(IShape::TPtr& shape) {
            shapes.erase(shape);
            view->Draw(shapes);
        }

        template <class F>
        void ForEachShape(F callback) const {
            std::for_each(shapes.cbegin(), shapes.cend(), callback);
        }

    private:
        void Render() {
        }

        TEditorView::TPtr view;
        std::unordered_set<IShape::TPtr> shapes;
    };

}
