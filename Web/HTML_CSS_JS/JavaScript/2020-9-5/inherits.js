//构造继承函数，封装继承信息
//Child --> Child.prototype --> Father.prototype --> Object.prototype
function inherits(Child, Father) {
    var f = function () { }    //空函数
    f.prototype = Father.prototype
    Child.prototype = new f()
    Child.prototype.constructor = Child
}

function Student(prop) {
    this.name = prop.name || 'Unamed'
}

Student.prototype.say = function () {
    return 'Hello,' + this.name + '!'
}

function PrimaryStudent(props) {
    Student.call(this, props)    //调用Student的构造函数
    this.grade = props.grade || 1
}

//原型继承
inherits(PrimaryStudent, Student)

PrimaryStudent.prototype.getGrade = function () {
    return this.grade
}



var s = new PrimaryStudent({ name: 'A', grade: 2 })
console.log(s.getGrade())


