#include "piece.h"

Piece::Piece(Type type, Color color)
    : m_type(type), m_color(color)
{}

Piece::~Piece()
{}

Piece::Type Piece::getType() const {
    return m_type;
}

Piece::Color Piece::getColor() const {
    return m_color;
}

QString Piece::getImage() const {
    return m_image;
}

void Piece::setImage(const QString& image) {
    m_image = image;
}

bool Piece::isBlack() const {
    return m_color == Color::Black;
}

bool Piece::isWhite() const {
    return m_color == Color::White;
}

