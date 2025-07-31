class Node {
    constructor(data){
        this.data = data;
        this.next = null;
    }
};

const a = new Node(20);
const b = new Node(30);
const c = new Node(50);
const d = new Node(90);
const e = new Node(250);

a.next = b;
b.next = c;
c.next = d;
d.next = e

function traverse (head){
    temp = head;
    while(temp != null){
        process.stdout.write(temp.data + " -> ");
        temp = temp.next;
    }
}

traverse(a);
