#include "tag.h"
#include <iostream>
#include <string>
using namespace std;

Tag::Tag(const string &type) 
	: type{type},
	  id{""}
{
	childrenLength = 0;
        childrenCapacity = 0;
	value = "";
	parent = nullptr;
	children = nullptr;
}

Tag::Tag(const Tag &other) {
	childrenCapacity = other.childrenCapacity;
	value = other.value;
	parent = other.parent;
	childrenLength = other.childrenLength;
	id = other.id;
	type = other.type;

	if (other.children != nullptr) {
		children = new Tag*[other.childrenCapacity];
		for (int i = 0; i < childrenLength; ++i) {
			children[i] = new Tag{*other.children[i]};
		}
	}
	if (other.children == nullptr) {
		children = nullptr;
	}
}

Tag::Tag(Tag &&other) 
	: childrenLength{other.childrenLength},
	  childrenCapacity{other.childrenCapacity},
	  id{other.id},
	  children{other.children},
	  value{other.value},
          parent{other.parent},
          type{other.type}
{
	other.parent = nullptr;
	other.children = nullptr;
}

Tag & Tag::operator=(const Tag &other) {
	if (this == &other) {
		return *this;
	}
	Tag *  t1 = other.parent? other.parent : nullptr;
	Tag** t2 = other.children? new Tag*[other.childrenCapacity] : nullptr;
	value = other.value;
	childrenCapacity = other.childrenCapacity;
	id = other.id;
	type = other.type;
	childrenLength = other.childrenLength;
	if (t2 != nullptr) {
		for (int j = 0; j < childrenLength; ++j) {
			t2[j] = new Tag{*other.children[j]};
		}
	}
	delete [] children;
	children = t2;
	parent = t1;
	return *this;
}

Tag & Tag::operator=(Tag &&other) {
	swap(children, other.children);
        swap(childrenLength, other.childrenLength);
	swap(type, other.type);
	swap(id, other.id);
	swap(value, other.value);
	swap(parent, other.parent);
	swap(childrenCapacity, other.childrenCapacity);
	return *this;
}

Tag::~Tag() {
	if (children != nullptr) {
		for (int k = 0; k < childrenLength; ++k) {
		delete children[k];
		}
	delete [] children;
	}
}

const string & Tag::getType() const {
	return type;
}
const string & Tag::getId() const {
	return id;
}
void Tag::setId(const string &_id) {
        id = _id;
}
const string & Tag::getValue() const {
	return value;
}
void Tag::setValue(const string &_value) {
	value = _value;
}
Tag * Tag::getParent() const {
	return parent;
}
void Tag::setParent(Tag *_parent) {
	parent = _parent;
}

Tag * Tag::getSelf() {
	return this;
}
void Tag::print(ostream &out, int indentLevel) const {
	if (indentLevel > 0) {
		int k = 0;
		while(k < indentLevel) {
			out << "  ";
			k++;
		}
	}
	out << '<' << type;
	if (id != "") {
		out << " id=";
	        out << '\'';
	        out << id << '\'';
	}
	if (value != "") {
		out << " value=";
	       out << '\'';
	      out  << value << '\'';
	}
	out << '>' << endl;
	if (children != nullptr) {
		int k = 0;
		while (k < childrenLength) {
			children[k]->print(out, indentLevel + 1);
			k++;
		}
	}
	if (indentLevel > 0) {
		int k = 0;
		while(k < indentLevel) {
			out << "  ";
			k++;
		}
	}
	out << "</";
        out << type << '>' << endl;
}
void Tag::addChild(Tag *other) {
	if (children == nullptr) {
		children = new Tag*[1];
		childrenLength = 1;
		childrenCapacity = 1;
		children[0] = other;
		children[0]->setParent(this);
		return;
	}

	if (childrenLength == childrenCapacity) {
		Tag **t = children;
		children = new Tag*[2 * childrenCapacity];
		for (int k = 0; k < childrenLength; ++k) {
			children[k] = t[k];
		}
		delete [] t;
		childrenCapacity *= 2;
	}
	children[childrenLength] = other;
	childrenLength++;
	children[childrenLength - 1]->setParent(this);
}

void Tag::removeChild(Tag *other) {
	if (children == nullptr) {
                return;
        }
	int k = -1;
	int m = 0;
	while(m < childrenLength) {
	if (children[m] == other) {
                        k = m;
                }
	m++;
	}
	if (k == -1) {
		return;
	}
	if (childrenLength == 1) {
		childrenLength = 0;
                childrenCapacity = 0;
		children[0] = nullptr;
		delete [] children;
		children = nullptr;
		return;
	}
	children[k] = nullptr;
	if (k != childrenLength - 1) {
	        for (int j = k + 1; j < childrenLength; ++j) {
		        children[j - 1] = children[j];
	        }
	}
	children[childrenLength - 1] = nullptr;
	childrenLength -= 1;
}

void Tag::remove(Tag *other) {
	if (children == nullptr) {
		return;
	}
	int k = -1;
	int m = 0;
	while(m <  childrenLength) {
		 if (children[m] == other) {
                        k = m;
                }
		 m++;
	}

	if (k == -1) {
		return;
	}
	if (childrenLength == 1) {
		childrenLength = 0;
                childrenCapacity = 0;
		delete children[0];
		delete [] children;
		children = nullptr;
		return;
	}
	delete children[k];
	if (k!= childrenLength - 1) {
		int n = k+1;
		while(n < childrenLength) {
			 children[n - 1] = children[n];
			 n++;
		}
	}
	children[childrenLength - 1] = nullptr;
	childrenLength -= 1;
}

Tag * Tag::findChild(string &type) {
	int k = 0;
	while(k < childrenLength) {
	if (children[k]->type == type) {
                        return children[k];
                }
	k++;
	}
	return nullptr;
}


Tag * Tag::findChildId(string &id) {
	int k = 0;
	while( k < childrenLength) {
		if (children[k]->id == id) {
                        return children[k];
                }
		k++;
	}
	return nullptr;
}


TagIterator Tag::begin() const {
	return TagIterator{children};
}


TagIterator Tag::end() const {
	return TagIterator{children + childrenLength};
}

TagIterator::TagIterator(Tag **t) 
	: t{t}
{}


Tag * TagIterator::operator*() const {
	return *t;
}


TagIterator TagIterator::operator++() {
	t = t + 1;
	return *this;
}


bool TagIterator::operator==(const TagIterator &other)const {
	return t == other.t;
}


bool TagIterator::operator!=(const TagIterator &other)const {
	return !(*this == other);
}


ostream &operator<<(ostream &out, const Tag &tag) {
	tag.print(out, 0);
	return out;
}

