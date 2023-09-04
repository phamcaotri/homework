document.addEventListener('DOMContentLoaded', function() {
    var output = document.getElementById('output');
    var input = document.getElementById('input');

    input.addEventListener('keydown', function(e) {
        if (e.key === 'Enter') {
            var command = input.value;
            input.value = '';

            output.innerHTML += '<p><span class="prompt">$</span> ' + command + '</p>';

            // Xử lý lệnh nhập vào ở đây
            processCommand(command);
        }
    });
});

function processCommand(command) {
    // Xử lý lệnh nhập vào và hiển thị kết quả tại đây
    // Ví dụ:
    if (command === 'hello') {
        output.innerHTML += '<p>Hello, world!</p>';
    } else {
        output.innerHTML += '<p>Command not found: ' + command + '</p>';
    }
}
