/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef LAYERDIAGRAMITEM_H
#define LAYERDIAGRAMITEM_H

#include <QGraphicsPixmapItem>
#include <QList>

#include "LayerGUIEnums.h"
#include "LayerProperties.h"
#include "CaffeTools.h"

QT_BEGIN_NAMESPACE
class QPixmap;
class QGraphicsItem;
class QGraphicsScene;
class QTextEdit;
class QGraphicsSceneMouseEvent;
class QMenu;
class QGraphicsSceneContextMenuEvent;
class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class QPolygonF;
QT_END_NAMESPACE

class Arrow;

class LayerDiagramItem : public QGraphicsItemGroup
{
public:
    enum { Type = UserType + 15 };

    LayerDiagramItem(LayerGUI::Layers layer, QMenu *contextMenu, int itemNum, QGraphicsItem *parent = 0);
    LayerDiagramItem(LayerGUI::Layers layer, QMenu *contextMenu, int topNum, LayerParameter layerParam, QGraphicsItem *parent = 0);

    void removeArrow(Arrow *arrow);
    void removeArrows();
    LayerGUI::Layers getLayer() const { return mLayer; }
    QPolygonF polygon() const { return mPolygon; }
    void* getLayerObject() const
    {
        return mLayerObject;
    }
    void addArrow(Arrow *arrow);
    QPixmap image() const;
    int type() const Q_DECL_OVERRIDE { return Type;}

    void setTopsBottoms();
    void setBlob();

    bool computationIsInPlace(LayerGUI::Layers layer);
    bool arrowIsForbidden(Arrow* arrow);

    string getLayerName();

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) Q_DECL_OVERRIDE;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

private:
    LayerGUI::LayerType initLayerType(LayerGUI::Layers layer, int itemNum);
    LayerGUI::LayerType initLayerType(LayerGUI::Layers layer, LayerParameter  layerParam, int topNum);

    LayerGUI::LayerType  mLayerType;
    LayerGUI::Layers     mLayer;
    QPolygonF            mPolygon;
    QMenu*               mContextMenu;
    QList<Arrow*>        mArrows;
    QBrush*              mBrush;
    QString              mLayerName;
    QString              mLayerInfo;
    QGraphicsPolygonItem mPolygonItem;
    QGraphicsTextItem    mLayerNameItem;
    QGraphicsTextItem    mLayerInfoItem;

    LayerProperties     *mProerties;

    void*                mLayerObject;
    void*                mDataBlob;

};

#endif // LAYERDIAGRAMITEM_H
