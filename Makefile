cc=clang

dirs:
	@mkdir -p dist

build: dirs
	@$(cc) -o dist/ci_cd_example main.c -O3

run: build
	@./dist/ci_cd_example https://google.com https://cashfree.com https://razorpay.com https://chatgpt.com | jq -s

