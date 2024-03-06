package main

import (
	"fmt"
	"log"
	"net/http"

	"github.com/TheFenrisLycaon/LibraryMS/pkg/routes"
	"github.com/gorilla/mux"
)

func main() {
	r := mux.NewRouter()
	routes.RegisterLibraryRoutes(r)
	http.Handle("/", r)
	fmt.Println("Server started at port 9010")
	log.Fatal(http.ListenAndServe(":9010", r))
}
